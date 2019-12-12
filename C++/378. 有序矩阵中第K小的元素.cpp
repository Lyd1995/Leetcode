#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;


struct cmp{
    bool operator()(const int &a, const int &b) const{
        return a > b;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority_queue<int, vector<int>, less<> > prio_q;   // 创建小顶堆
        priority_queue<int> prio_q; // 创建大顶堆
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[i].size(); j++){
                if(prio_q.size() < k)
                    prio_q.push(matrix[i][j]);
                else {  // 此时，每次替换掉最大的元素
                    if(prio_q.top() > matrix[i][j]){
                        prio_q.pop();
                        prio_q.push(matrix[i][j]);
                    }
                }
            }
        }
        return prio_q.top();
    }
};