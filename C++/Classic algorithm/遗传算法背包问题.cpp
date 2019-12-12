#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

#define POPULATION_SIZE 32
#define OBJ_COUNT 7
#define CAPACITY 150
#define P_XOVER 0.8
#define P_MUTATION 0.15

int Weight[] = {35,30,60,50,40,10,25};
int Value[] = {10,40,30,50,35,40,30};

/*
0-1背包问题

现在有7个物体，编号为：1~7
重量：w = {35,30,60,50,40,10,25}
价值：p = {10,40,30,50,35,40,30}

背包承重：150
*/

// 个体编码
typedef struct GAType {
    // 基因：大小为OBJ_COUNT，因为一共有7个可供选择的物体
    int gene[OBJ_COUNT];
    // 适应度
    int fitness;
    // 选择概率、积累选择概率
    double rf, cf;
} GATYPE;

class Solution {
public:
    Solution(int num){
        population = vector<GATYPE>(POPULATION_SIZE);
        MAX_GENERATIONS = num;
        Init(population);
    }

    // 遗传算法，评估函数
    int EnvaluateFitness(vector<GATYPE>& pop){
        // 定义群体的适应度
        int totalFitness = 0;
        for(int i=0; i < pop.size(); i++){
            int tw = 0;
            pop[i].fitness = 0;
            // 计算个体的适应度
            for(int j=0; j < OBJ_COUNT; j++){
                if(pop[i].gene[j] == 1){
                    tw += Weight[j];
                    pop[i].fitness += Value[j];
                }
            }
            if(tw > CAPACITY)
                pop[i].fitness = 1;
            totalFitness += pop[i].fitness;
        }

        return totalFitness;
    }

    // 选择算子： 轮盘赌算法
    // 计算： 群体适应度  与  个体适应度  
    // 个体被选择的概率 = 个体适应度 / 群体适应度
    void Select(int totalFitness, vector<GATYPE>& pop){
        // 计算个体的选择概率与累积选择概率
        vector<GATYPE> newPop(pop.size());
        double lastCf = 0.0;
        // 计算概率
        for(int i=0; i < pop.size(); i++){
            pop[i].rf = (double)pop[i].fitness / totalFitness;
            pop[i].cf = lastCf + pop[i].rf;
            lastCf = pop[i].cf;
        }

        // 选择下一代
        for(int i=0; i < newPop.size(); i++){
            double p = computeP();
            // 选择个体
            if(p < pop[0].cf)
                newPop[i] = pop[0];
            else {
                for(int j=0; j < pop.size() - 1; j++){
                    if(p >= pop[j].cf && p < pop[j + 1].cf){
                        newPop[i] = pop[j];
                        break;
                    }
                }
            }
        }
        // 赋值
        pop = newPop;
    }

    // 交叉算子：多点交叉策略（基因交换的位置和个数都是随机选择）
    void Crossover(vector<GATYPE>& pop){
        // 选择一个需要交换的个体
        int first = -1;

        for(int i=0; i < pop.size(); i++){
            double p = computeP();
            if(p < P_XOVER){
                if(first < 0)
                    first = i;
                else {
                    Exchange(pop, first, i);
                    first = -1;
                }
            }
        }
    }
    // 交换函数
    void Exchange(vector<GATYPE>& pop, int first, int second){
        // 随机决定交换的基因个数
        int ecc = rand() % OBJ_COUNT + 1;
        for(int i=0; i < ecc; i++){
            // 每个位置被交换的概率相同
            int idx = rand() % OBJ_COUNT;
            // 交换idx位置上的基因
            int temp = pop[first].gene[idx];
            pop[first].gene[idx] = pop[second].gene[idx];
            pop[second].gene[idx] = temp;
        }
    }

    // 变异算子
    void Mutation(vector<GATYPE>& pop){
        for(int i=0; i < pop.size(); i++){
            double p = computeP();
            if(p < P_MUTATION)
                ReverseGene(pop, i);
        }
    }

    // 基因突变（因为基因只有：0 和 1，突变导致：   0变1    1变0）
    void ReverseGene(vector<GATYPE>& pop, int k){
        // 基因突变的个数是随机的
        int mcc = rand() % OBJ_COUNT + 1;
        for(int i=0; i < mcc; i++){
            // 基因突变的位置是随机的
            int idx = rand() % OBJ_COUNT;
            pop[k].gene[idx] = 1 - pop[k].gene[idx];
        }
    }

    // 随机初始化
    void Init(vector<GATYPE>& pop){
        for(int i=0; i < pop.size(); i++){
            for(int j=0; j < OBJ_COUNT; j++){
                double p = computeP();
                pop[i].gene[j] = 0;
                if(p < 0.5)
                    pop[i].gene[j] = 1;
            }
        }
    }

    // 运行遗传算法
    int run(){
        totalFitness = EnvaluateFitness(population);
        for(int i=0; i < MAX_GENERATIONS; i++){
            Select(totalFitness, population);
            Crossover(population);
            Mutation(population);
            totalFitness = EnvaluateFitness(population);
        }
        int ans = 0;
        for(int i=0; i < population.size(); i++){
            if(population[i].fitness > ans)
                ans = population[i].fitness;
        }
        return ans;
    }

    // 计算概率
    double computeP(){
        int a = rand() % 10000;
        double ans = (double) a / 10000;
        return ans;
    }

private:
    vector<GATYPE> population;
    int totalFitness, MAX_GENERATIONS;
};



int main() {
    Solution a(50000);

    a.run();
}
