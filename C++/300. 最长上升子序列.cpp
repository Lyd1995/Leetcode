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
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]表示以nums[i]为最大数的最长公共子序列的长度
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for(int i=1; i < nums.size(); i++){
            int max_l = 0;
            for(int j=i-1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > max_l)
                        max_l = dp[j] + 1;
                }
            }
            dp[i] = max(max_l, 1);
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};