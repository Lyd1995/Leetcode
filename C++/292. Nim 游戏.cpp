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
    bool canWinNim(int n) {
        vector<bool> dp(n + 5);
        dp[0] = true;
        dp[1] = true;

        return dp[n];
    }
};