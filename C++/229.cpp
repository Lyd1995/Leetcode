#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

class Solution1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n_3 = nums.size() / 3;
        for(int i=0; i < nums.size(); i++){
            int count = 0;
            int num = nums[i];
            while(i < nums.size() && nums[i] == num){
                i++;
                count++;
            }
            if(count > n_3)
                ans.push_back(num);
            i--;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = nums[0], num2 = nums[0];
        int count1 = 0, count2 = 0;
        // 确定两个可能的候选者
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == num1){
                count1++;
                continue;
            }
            if(nums[i] == num2){
                count2++;
                continue;
            }
            if(count1 == 0){
                num1 = nums[i];
                count1++;
                continue;
            }
            if(count2 == 0){
                num2 = nums[i];
                count2++;
                continue;
            }
            count1--;
            count2--;
        }
        vector<int> ans;
        // 重新统计两位候选者的票数
        count1 = count2 = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == num1){
                count1++;
                continue;
            }
            if(nums[i] == num2){
                count2++;
                continue;
            }
        }
        if(count1 > nums.size() / 3)
            ans.push_back(num1);
        if(count2 > nums.size() / 3)
            ans.push_back(num2);
        return ans;
    }
};

int main(){
    Solution a;
    vector<int> v = {3, 2, 3};
    a.majorityElement(v);
}