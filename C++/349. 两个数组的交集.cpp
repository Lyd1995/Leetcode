#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1_;
        for(int i=0; i < nums1.size(); i++)
            nums1_.insert(nums1[i]);
        set<int> ans;
        for(int i=0; i < nums2.size(); i++){
            if(nums1_.count(nums2[i]))
                ans.insert(nums2[i]);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};