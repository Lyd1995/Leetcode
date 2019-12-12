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


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        if(nums.size() == 2){
            if(nums[0] == nums[1])
                return 1;
            else
                return 2;
        }
        vector<int> diff(nums.size(), 0);
        for(int i=1; i < nums.size(); i++){
            diff[i] = nums[i] - nums[i - 1];
            if(diff[i] > 0)
                diff[i] = 1;
            if(diff[i] < 0)
                diff[i] = -1;
        }
        // 求最长子序列
        // dp[i]:以nums[i]为终点的最长子序列长度
        // flag = 0,任意数字都能匹配，
        int maxLen = 0, ans = 1;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        if(diff[1] != 0){
            dp[1] = 2;
            ans = 2;
        }
        for(int i = 2; i < dp.size(); i++){
            int curMax = 0;
            for(int j = i - 1; j > 0; j--){
                if(diff[i] == 0)
                    continue;
                if(diff[i] == -diff[j]){
                    if(dp[j] > curMax)
                        curMax = dp[j];
                }
            }
            if(curMax == 0 && nums[i] != nums[0])
                curMax = 1;
            dp[i] = curMax + 1;
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};