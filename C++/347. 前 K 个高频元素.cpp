#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef pair<int, int> pair2;

typedef pair<int, int> numAndFrequent;

struct cmp {
    bool operator()(const pair2 &left, const pair2 &right) const{
        return left.second > right.second;
    }
};


class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        priority_queue<pair2, vector<pair2>, cmp> q;
        for(int i=0; i < nums.size(); i++){
            hash[nums[i]]++;
        }
        vector<int> ans;
        for(auto item : hash){
            if(q.size() < k)
                q.push(item);
            else{
                if(item.second > q.top().second){
                    q.pop();
                    q.push(item);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<
    }
};