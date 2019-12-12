#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        // 动态规划算法
        // dp[i]表示到nums[i]为止，所能获得的最大收益
        vector<int> dp(nums.size());
        int ans1, ans2;
        //bool isMax;
        computeMoney(nums, dp, ans1);
        reverse(nums);
        computeMoney(nums, dp, ans2);
        return (ans1 > ans2) ? ans1 : ans2;
    }

    void computeMoney(vector<int>& nums, vector<int>& dp, int& ans){
        bool flag, begin;
        int len = dp.size();
        dp[0] = nums[0];
        // 使用了nums[i-1]
        if(nums[1] > nums[0]){
            dp[1] = nums[1];
            flag = true;
        }
        else{
            dp[1] = nums[0];
            flag = false;
        }
        for(int i=2; i < len; i++){
            if(flag){
                if(dp[i - 1] > dp[i - 2] + nums[i]){
                    dp[i] = dp[i - 1];
                    flag = false;
                }
                else{
                    dp[i] = dp[i - 2] + nums[i];
                    flag = true;
                }
            }
            else{
                dp[i] = dp[i - 1] + nums[i];
                flag = true;
            }
        }
        if(flag)
            ans = dp[len - 2];    // 不计算最后一位
        else
            ans = dp[dp.size() - 1];
    }

    void reverse(vector<int>& nums){
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
};

int main(){
    vector<int> v = {1, 2, 3, 1};
    Solution a;
    a.rob(v);
}