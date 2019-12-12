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
    int numSquares(int n) {
        squares = vector<long>(n + 5, 0);
        dp = vector<int>(n + 5, 0);
        init(n);
        return solve(n);
    }

    int solve(int& n){
        // 计算
        for(int k=2; k <= n; k++){
            if(dp[k] == 0){
                int min_num = k;
                for(int i=1; k - i * i >= 0; i++){
                    int temp = dp[k - i * i] + 1;
                    if(temp < min_num)
                        min_num = temp;
                }
                dp[k] = min_num;
            }
        }
        return dp[n];
    }

    void init(int n){
        for(int i=1; i <= n; i++){
            long temp = pow(i, 2);
            squares[i] = temp;
            if(temp > n){
                squares[i] = 0;
                break;
            }
        }
        // 初始化平方数
        for(int i=1; i < squares.size(); i++){
            if(squares[i] == 0)
                break;
            dp[squares[i]] = 1;
        }
    }
private:
    vector<long> squares;
    vector<int> dp;
};