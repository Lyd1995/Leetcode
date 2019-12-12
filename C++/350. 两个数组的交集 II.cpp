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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i1 = 0, i2 = 0;
        while(i1 < nums1.size() && i2 < nums2.size()){
            if(nums1[i1] == nums2[i2]){
                ans.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] < nums2[i2])
                i1++;
            else
                i2++;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nums1_, nums2_;
        for(int i=0; i < nums1.size(); i++)
            nums1_[nums1[i]]++;
        vector<int> ans;
        for(int i=0; i < nums2.size(); i++)
            nums2_[nums2[i]]++;
        map<int, int>::iterator it1 = nums1_.begin(), it2 = nums2_.begin();
        while(it1 != nums1_.end() && it2 != nums2_.end()){
            if(it1->first == it2->first){
                int len = min(it1->second, it2->second);
                ans.insert(ans.end(), len, it1->first);
                it1++;
                it2++;
            }
            else if(it1->first < it2->first)
                it1++;
            else
                it2++;

        }
        return ans;
    }
};