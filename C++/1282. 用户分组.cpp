#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<math.h>
using namespace std;

typedef pair<int, int> pair2;

struct cmp {
    bool operator()(const pair2 &left, const pair2 &right) const{
        return left.second > right.second;
    }
};

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        priority_queue<pair2, vector<pair2>, cmp> q;
        for(int i=0; i < groupSizes.size(); i++){
            pair2 temp(i, groupSizes[i]);
            q.push(temp);
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            pair2 temp = q.top();
            q.pop();
            int g_size = temp.second;
            vector<int> t;
            t.push_back(temp.first);
            while(t.size() != g_size){
                pair2 temp2 = q.top();
                q.pop();
                t.push_back(temp2.first);
            }
            ans.push_back(t);
        }
        return ans;
    }
};