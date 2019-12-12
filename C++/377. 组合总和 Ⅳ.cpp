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


// 回溯算法
class Solution {
public:
    int ans;
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ans = 0;
        dfs(nums, 0, target);
        return ans;
    }

    void dfs(vector<int>& nums, int pre_sum, int target){
        if(pre_sum < target){
            for(int i=0; i < nums.size(); i++){
                pre_sum += nums[i];
                if(pre_sum > target)
                    break;
                dfs(nums, pre_sum, target);
                pre_sum -= nums[i];
            }
        }
        else if(pre_sum == target)
            ans++;
        return;
    }
};

// 动态规划
class Solution {
public:
    int ans;
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dp = vector<int>(target + 1, -1);
        dp[0] = 1;
        return solve(nums, target);
    }

    int solve(vector<int>& nums, int target){ 
        if(target < 0)
            return 0;       
        // 计算：dp[target - nums[i]]
        for(int i=0; i < nums.size(); i++){
            if(nums[i] > target)
                break;
            if(dp[target - nums[i]] == -1)
                dp[target - nums[i]] = solve(nums, target - nums[i]);
        }
        // 求解dp[target]
        dp[target] = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] > target)
                break;
            dp[target] += dp[target - nums[i]];
        }

        return dp[target];
    }
};