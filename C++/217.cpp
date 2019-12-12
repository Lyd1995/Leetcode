#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> list;
        for(int i=0; i < nums.size(); i++){
            if(list.count(nums[i]))
                return true;
            list.insert(map<int, int>::value_type(nums[i], i));
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> list;
        for(int i=0; i < nums.size(); i++){
            if(list.count(nums[i])){
                if(i - list[nums[i]] <= k)
                    return true;
                list[nums[i]] = i;
            }
            else
                list.insert(map<int, int>::value_type(nums[i], i));
        }
        return false;
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, ListNode*> list;
        for(int i=0; i < nums.size(); i++){
            if(list.count(nums[i])){
                ListNode* temp = list[nums[i]];
                ListNode* p = temp;
            }
            else{
                ListNode* temp = new ListNode(i);
                list.insert(map<int, ListNode*>::value_type(nums[i], temp));
            }
        }
        return false;
    }
};