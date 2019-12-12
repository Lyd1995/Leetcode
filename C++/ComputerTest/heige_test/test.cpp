#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<sstream>
using namespace std;


class system_save{
public:
    system_save(){
        small_empty = 0;
        mid_empty = 0;
        lager_empty = 0;
        sizeStr2sizeInt_hash.insert(pair<string, int>("s", 1));
        sizeStr2sizeInt_hash.insert(pair<string, int>("m", 2));
        sizeStr2sizeInt_hash.insert(pair<string, int>("l", 3));
    }

    void entryContainer(int l, int m, int s){
        small_empty += s;
        mid_empty += m;
        lager_empty += l;
        // 创建箱子,0：表示箱子空的，1：小货物，2：中，3：大
        size2container_hash = vector<vector<int> >(4, vector<int>());
        size2container_hash[1] = vector<int>(small_empty, 0);
        size2container_hash[2] = vector<int>(mid_empty, 0);
        size2container_hash[3] = vector<int>(lager_empty, 0);
    }

    void waitCommand(){
        cout << "begin input command \n"; 
        while(true){
            string line;
            getline(cin, line);
            vector<string> command = divideString(line);

            for(int i=0; i < command.size(); i++)
                cout << command[i] << "   ";
            cout << endl;

            // 存储货物
            if(command[0] == "s"){
                storeCommodity(command[1], stoi(command[2]));
            }
            // 录入箱子
            else if(command[0] == "in"){
                int s, m, l, i = 1;
                for(int i=1; i < command.size(); i++){
                    if(command[i] == "s")
                        s = stoi(command[++i]);
                    else if(command[i] == "m")
                        m = stoi(command[++i]);
                    else
                        l = stoi(command[++i]);
                }
                cout << "s = " << s << "\n" << "m = " << m << "\n" << "s = " << s << "\n";
                entryContainer(l, m, s);
            }
            // 查询
            else if(command[0] == "inquiry"){
                inquiry();
            }
        }
    }

    vector<string> divideString(string &s){
        int j = 0;
        vector<string> ans;
        while(j < s.size()){
            if(s[j] == '\n')
                break;
            removeSpace(s, j);
            int i = j;
            while(s[j] != ' ' && s[j] != '\n')
                j++;
            if(i != j)
                ans.push_back(s.substr(i, j - i));
        }
        return ans;
    }

    void removeSpace(string &s, int &i){
        while(s[i] == ' ')
            i++;
    }

    void storeCommodity(string commodity, int num){
        int commodity_size = sizeStr2sizeInt_hash[commodity];
        switch (commodity_size){
            case 1:
                while(num){
                    if(small_empty){
                        consumeContainer(small_empty, num, commodity_size);
                    }
                    else if(mid_empty){
                        consumeContainer(mid_empty, num, commodity_size);
                    }
                    else if(lager_empty){
                        consumeContainer(lager_empty, num, commodity_size);
                    }
                    else
                        cout << "箱子不够，放不下！" << endl;
                }
                break;
            case 2:
                while(num){
                    // 当存在空闲箱子的时候，可以采取小货物的存储策略
                    if(mid_empty)
                        consumeContainer(mid_empty, num, commodity_size);
                    else if(lager_empty)
                        consumeContainer(lager_empty, num, commodity_size);
                    // 不存在空闲的大、中箱子，要搬动货物
                    else{
                        int state = midMove(num);
                        if(state){
                            cout << "装不下！！" << endl;
                            break;
                        }
                    }  
                }
                break;
            case 3:
                while(num){
                    if(lager_empty)
                        consumeContainer(lager_empty, num, commodity_size);
                    // 大箱子不足，需要移动
                    else{
                        // 我们需要腾出：commodity_num个大箱子，但是这commodity_num个大箱子里面装的可能有小货物、中货物
                        if(num > small_empty + mid_empty){
                            cout << "装不下！！" << endl;
                            break;
                        }
                        // 先将大箱子中的小货物处理完：
                        lagerMoveSmall(num);
                        // 腾出空间了
                        if(lager_empty)
                            consumeContainer(lager_empty, num, commodity_size);
                        // 若还需要空间，接着处理大箱子的中货物
                        if(num)
                            lagerMoveMid(num);
                    }
                }
                break;
            default:
                break;
        }
    }

    // 货物的消耗策略
    void consumeContainer(int &container_num, int &commodity_num, int commodity_size){
        if(container_num >= commodity_num) {
            container_num -= commodity_num;
            int k = 0;
            for(int i=0; i < size2container_hash[commodity_size].size(); i++){
                if(size2container_hash[commodity_size][i] == 0){
                    size2container_hash[commodity_size][i] = commodity_size;
                    k++;    
                }
                if(k == commodity_num)
                    break;
            }
            commodity_num = 0;
        }
        else{
            commodity_num -= container_num;
            int k = 0;
            for(int i=0; i < size2container_hash[commodity_size].size(); i++){
                if(size2container_hash[commodity_size][i] == 0){
                    size2container_hash[commodity_size][i] = commodity_size;
                    k++;    
                }
                if(k == container_num)
                    break;
            }
            container_num = 0;
        }
    }

    // 中货物所需箱子不足时的搬运策略
    int midMove(int commodity_num){
        // 此时搬运也没用
        if(commodity_num > small_empty)
            return -1;
        // 搬运中箱子中的货物
        // k需要搬运的箱子数量
        int k = 0;
        // 搬运中箱子的货物
        for(int i=0; i < size2container_hash[2].size(); i++){
            if(size2container_hash[2][i] == 1){
                size2container_hash[2][i] = 0;
                mid_empty++;
                k++;
            }
            if(k == commodity_num){
                consumeContainer(small_empty, k, 1);
                return 0;
            }
        }
        // 搬运大箱子中的小货物
        for(int i=0; i < size2container_hash[3].size(); i++){
            if(size2container_hash[3][i] == 1){
                size2container_hash[3][i] = 0;
                lager_empty++;
                k++;
            }
            if(k == commodity_num){
                consumeContainer(small_empty, k, 1);
                return 0;
            }
        }
        return 0;
    }

    // 大货物所需箱子不足时的小货物搬运策略
    void lagerMoveSmall(int commodity_num){
        // 小箱子空间不足
        /* commodity_num ： 是这次总共需要搬运的箱子数量
           我们需要腾出：commodity_num个大箱子，但是这commodity_num个大箱子里面装的可能有小货物、中货物
        */
        // k：靠小箱子腾出来的空间，因此 k <=  commodity_num
        int k = 0;
        for(int i=0; i < size2container_hash[3].size(); i++){
            if(size2container_hash[3][i] == 1){
                size2container_hash[3][i] = 0;
                lager_empty++;
                k++;
            }
            if(k == commodity_num)
                break;
        }
        // 将大箱子的小货物搬到小箱子
        consumeContainer(small_empty, k, 1);
        // 小箱子数量不足，使用中箱子
        if(k){
            consumeContainer(mid_empty, k, 1);
        }
    }

    // 大货物所需箱子不足时的中货物搬运策略
    void lagerMoveMid(int commodity_num){       
        int k = 0;
        for(int i=0; i < size2container_hash[3].size(); i++){
            if(size2container_hash[3][i] == 2){
                size2container_hash[3][i] = 0;
                lager_empty++;
                k++;
            }
            if(k == commodity_num)
                break;
        }
        consumeContainer(mid_empty, k, 2);
    }

    void inquiry(){
        cout << "大箱子剩余：" << lager_empty << endl;
        cout << "中箱子剩余：" << mid_empty << endl;
        cout << "小箱子剩余：" << small_empty << endl;
    }



private:
    // 计算空箱子数量
    int small_empty, mid_empty, lager_empty;
    // 映射
    map<string, int> sizeStr2sizeInt_hash;
    // 箱子
    vector<vector<int> > size2container_hash;
};


int main() {
    system_save a;
    // cout << "qidong";
    a.waitCommand();
}