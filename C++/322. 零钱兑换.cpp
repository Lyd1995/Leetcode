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
    vector<int> table;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int m = 0;
        while(m < coins.size() && coins[m] <= amount)
            m++;
        vector<int> use(coins.begin(), coins.begin() + m);
        table = vector<int>(amount + 5, -2);
        table[0] = 0;
        for(int i=0; i < use.size(); i++)
            table[use[i]] = 1;
        return dp(use, amount);
    }

    int dp(vector<int>& coins, int amount){
        if(table[amount] != -2)
            return table[amount];
        int ans = INT32_MAX, temp;
        for(int i=0; i < coins.size(); i++){
            int num = amount - coins[i];
            if(num < 0)
                continue;
            temp = 1 + dp(coins, num);
            if(temp > 0 && ans > temp)
                ans = temp;
        }
        if(ans == INT32_MAX)
            ans = -1;
        table[amount] = ans;
        return table[amount];
    }
};


int main(){
    vector<int> nums = {456, 117, 5, 145};
    // [456,117,5,145]
    Solution a;
    auto b = a.coinChange(nums, 1459);
    return 0;
}