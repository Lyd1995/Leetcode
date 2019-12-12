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
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        int len = prices.size();
        if(k < len){
            vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, 0)));
            // 第0天的初始化
            for(int i=0; i <= k; i++){
                dp[0][i][1] = -prices[0];
            }
            for(int i=1; i < prices.size(); i++){
                dp[i][0][0] = dp[i-1][0][0];
                for(int j=1; j <= k; j++){
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                }
            }
            return dp[prices.size() - 1][k][0];
        }
        else{
            vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
            dp[0][1] = -prices[0];
            for(int i=1; i < prices.size(); i++){
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            }
            return dp[len - 1][0];
        }
    }
};