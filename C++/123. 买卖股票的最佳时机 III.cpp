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
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, 0)));
        // 第0天的初始化
        dp[0][0][1] = -prices[0];
        dp[0][1][1] = -prices[0];
        dp[0][2][1] = -prices[0];
        for(int i=1; i < prices.size(); i++){
            dp[i][0][0] = dp[i - 1][0][0];
            dp[i][1][0] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][1][0]);
            dp[i][1][1] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][1]);
            dp[i][2][0] = max(dp[i - 1][2][1] + prices[i], dp[i - 1][2][0]);
            dp[i][2][1] = max(dp[i - 1][1][0] - prices[i], dp[i - 1][2][1]);
        }
        return dp[prices.size() - 1][2][0];
    }
};

int main(){
    vector<int> v = {3,3,5,0,0,3,1,4};
    Solution a;
    a.maxProfit(v);

}