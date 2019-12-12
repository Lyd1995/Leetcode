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


class Solution {
public:
    struct  cmp{
        bool operator() (const pair<int, int> &a, const pair<int, int> &b){
            return a.first + a.second < b.first + b.second;
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;  // 最大的元素在上面
        for(int i=0; i < nums1.size(); i++){
            for(int j=0; j < nums2.size(); j++){
                if(q.size() < k)
                    q.push(pair(nums1[i], nums2[j]));
                else{
                    if(nums1[i] + nums2[j] < q.top().first + q.top().second){
                        q.pop();
                        q.push(pair(nums1[i], nums2[j]));
                    }
                }
            }
        }
        while(!q.empty()){
            vector<int> temp = {q.top().first, q.top().second};
            ans.push_back(temp);
            q.pop();
        }
        return ans;
    }
};