#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<sstream>
using namespace std;


// 回溯算法
class Solution1 {
public:
    int ans;
    int maxSumDivThree(vector<int>& nums) {
        ans = 0;
        solve(nums, 0, 0);
        return ans;
    }

    void solve(vector<int>& nums, int pre, int pre_sum){
        if(pre_sum > ans && pre_sum % 3 == 0)
            ans = pre_sum;
        for(int i=pre; i < nums.size(); i++){
            pre_sum += nums[i];
            solve(nums, i + 1, pre_sum);
            pre_sum -= nums[i];
        }
        return;
    }
};


class Solution {
public:
    int ans;
    int maxSumDivThree(vector<int>& nums) {
        // dp0:能被3整除的最大整数和
        // dp1：余1的最大整数和
        // dp2：余2的最大整数和
        // vector<int> dp0(nums.size() + 1, 0), dp1(nums.size() + 1, 0), dp2(nums.size() + 1, 0);
        vector<vector<int>> dp(3, vector<int>(nums.size(), 0));
        dp[nums[0] % 3][0] = nums[0];
        int sum = nums[0];
        for(int i=1; i < nums.size(); i++){
            int sum0 = dp[0][i - 1] + nums[i];
            int sum1 = dp[1][i - 1] + nums[i];
            int sum2 = dp[2][i - 1] + nums[i];
            dp[sum0 % 3][i] = max(sum0, max(dp[sum0 % 3][i], dp[sum0 % 3][i - 1]));
            dp[sum1 % 3][i] = max(sum1, max(dp[sum1 % 3][i], dp[sum1 % 3][i - 1]));
            dp[sum2 % 3][i] = max(sum2, max(dp[sum2 % 3][i], dp[sum2 % 3][i - 1]));

            // 更新迭代值
            for(int j=0; j < 3; j++){
                if(dp[j][i] == 0)
                    dp[j][i] = dp[j][i - 1];
            }
        }

        return dp[0][nums.size() - 1];
    }
};