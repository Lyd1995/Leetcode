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

// 二分法策略（错误的方法）
class Solution1 {
public:
    int getMoneyAmount(int n) {
        int low = 1, high = n, ans = 0, mid;
        int num = (int) (log(n) / log(2));
        while(num--){
            mid = (low + high) / 2;
            ans += mid;
            low = mid;
        }
        return ans;
    }
};

// 二分法为什么错了呢？
// 实际上二分法是使用最少的次数来猜对这个数字，而不是最少的代价
// 左闭右闭
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i=1; i < n; i++)
            dp[i][i + 1] = i;
        for(int len=2; len < n; len++){
            for(int i=1; i < n; i++){
                int j = i + len;
                if(j > n)
                    break;
                int min_t = INT32_MAX;
                for(int k=i; k <= j; k++){
                    int temp = k + max(dp[i][k - 1], dp[k + 1][j]);
                    if(min_t > temp)
                        min_t = temp;
                }
                dp[i][j] = min_t;
            }
        }
        return dp[1][n];
    }
};

int main(){
    Solution a;
    a.getMoneyAmount(6);

    return 0;
}