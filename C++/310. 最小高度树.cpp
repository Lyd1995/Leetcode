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

class Solution {
public:
    vector<vector<int>> nodes_table;
    vector<int> degree;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return vector<int>(0);
        nodes_table = vector<vector<int>>(n);
        degree = vector<int>(n, 0);
        initialTable(n, edges);
        queue<int> nodes;
        // 先从叶节点找起，因为图具有树特征，因此，叶节点的度为1（这里的度表示：出度与入度，任意节点都有父节点，叶节点无子节点）
        // 第一次找出所有的叶节点
        vector<int> list1(n, 0);
        for(int node=0; node < n; node++){
            if(degree[node] == 1){
                nodes.push(node);
                list1[node]++;
            }
        }
        int num = n;
        // 从最外围的叶节点起，一圈一圈的减少节点数量，直到节点数量为1或者2时，停止
        while(num > 2){
            int len = nodes.size();
            num -= len;
            for(int i=0; i < len; i++){
                int node = nodes.front();
                nodes.pop();
                for(auto id : nodes_table[node]){
                    degree[id]--;
                    if(list1[id] == 0 && degree[id] == 1) {// 经过一圈减少后，若度=1，则变为新的叶节点
                        nodes.push(id);
                        list1[id]++;
                    }
                }
            }
        }
        vector<int> ans;
        while(!nodes.empty()){
            ans.push_back(nodes.front());
            nodes.pop();
        }
        return ans;
    }

    void initialTable(int& n,vector<vector<int>>& edges){
        for(auto edge : edges){
            nodes_table[edge[0]].push_back(edge[1]);
            nodes_table[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
    }
};

int main(){
    vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    Solution a;
    a.findMinHeightTrees(6, edges);
}