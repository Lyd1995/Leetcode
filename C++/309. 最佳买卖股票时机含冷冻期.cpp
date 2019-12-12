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
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // 初始化
        dp[0][1] = -prices[0];
        dp[1][1] = (-prices[0] > -prices[1]) ? -prices[0] : -prices[1];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        // 动态规划
        for(int i=2; i < prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};