#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<math.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 10, 0);
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 91;
        for(int i=3; i <= n; i++)
            dp[i] = numberOfUnique(dp, i);
        return dp[n];
    }

    int numberOfUnique(vector<int>& dp, int n){
        return dp[n - 1] + computeA(9, n) + computeA(9, n - 1) * (n - 1);
    }

    // 计算A(n, m)
    int computeA(int n, int m){
        long long ele = 1, deno = 1;
        m = n - m;
        int i = 2;
        while(i <= n){
            ele *= i;
            i++;
        }
        i = 2;
        while(i <= m){
            deno *= i;
            i++;
        }
        int ans = ele / deno;
        return ans;
    }
};