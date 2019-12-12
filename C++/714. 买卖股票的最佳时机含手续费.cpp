#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


class Solution1 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector< vector<int>> dp(prices.size(), vector<int>(prices.size(), 0));
        // 初始化dp数组
        for(int i=0; i < prices.size() - 1; i++){
            int fit = prices[i + 1] - prices[i] - fee;
            dp[i][i + 1] = (fit > 0) ? fit : 0;
        }

        // 根据动态规划方程，求解
        for(int len=2; len < prices.size(); len++){
            for(int i=0; i < prices.size() - len; i++){
                int j = i + len;
                int max_val = prices[j] - prices[i] - fee;
                for(int k=i+1; k < j; k++){
                    int val;
                    val = dp[i][k] + dp[k][j];
                    if(val > max_val)
                        max_val = val;
                }
                dp[i][j] = max_val;
            }
        }
        return dp[0][prices.size() - 1];
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sale=prices[prices.size()-1], pre_sale=0, pur=0, fit;
        int profit=0, cur_profit=0, pre_profit=0;
        for(int i=prices.size()-2; i >= 0; i--){
            if(prices[i] > sale){
                sale = prices[i];
                continue;
            }
            // 准备买卖
            pur = prices[i];
            cur_profit = sale - pur - fee;
            fit = pre_sale - pur - fee;
            if(fit > 0 && fit >= max_int(pre_profit + cur_profit, pre_profit)){
                    profit = profit - pre_profit + fit;
                    pre_profit = fit;
                    sale = pur;
                    continue;
            }
            if(cur_profit > 0){
                profit += cur_profit;
                pre_profit = cur_profit;
                pre_sale = sale;
                sale = pur;
            }
        }
        return profit;
    }

    int max_int(int a, int b){
        if(a > b)
            return a;
        else
            return b;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // 初始化
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1] - fee);
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);
        // 状态转移
        for(int i=2; i < prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};

int main(){
    Solution a;
    vector<int> nums = {1, 3, 2, 8, 4, 9};
    a.maxProfit(nums, 2);
}

/*
[1,3,7,5,10,3]
3

[2,2,1,1,5,5,3,1,5,4]
2
 */