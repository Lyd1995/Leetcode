#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 2, 1);
        for(int i=3; i <= n; i++){
            int max_num = 0;
            for(int j=1; j <= i / 2; j++){
                int temp = max(dp[j], j) * max(dp[i - j], i - j);
                if(temp > max_num)
                    max_num = temp;
            }
            dp[i] = max_num;
        }
        return dp[n];
    }
};