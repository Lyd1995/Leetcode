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
    int findLHS(vector<int>& nums) {
        // dp[i]:表示以nums[i]为最小值的最长和谐子序列的长度
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        for(int i=0; i < nums.size(); i++) {
            bool flag = true;
            for(int j=i; j < nums.size(); j++){
                int d = nums[j] - nums[i];
                if(d > 1)
                    break;
                if(d == 1)
                    flag = false;
                dp[i]++;
            }
            if(flag)
                dp[i] = 0;
        }
        int ans = 0;
        for(auto len : dp){
            if(len > ans)
                ans = len;
        }
        return ans;
    }
};