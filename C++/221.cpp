#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        // 动态规划
        int max_i = matrix.size(), max_j = matrix[0].size();
        // dp[i][j]表示以（i,j）为右下角的矩形所能找到的正方形的边长
        vector<vector<int>> dp(max_i, vector<int>(max_j, 0));
        // 初始化第一列
        int max_edge=0;
        for(int i=0; i < max_i; i++){
            if(matrix[i][0] == '1')
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
            if(max_edge < dp[i][0])
                max_edge = 1;
        }
        // 初始化第一行
        for(int j=1; j < max_j; j++){
            if(matrix[0][j] == '1')
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
            if(max_edge < dp[0][j])
                max_edge = 1;
        }
        // dp
        for(int i=1; i < max_i; i++){
            for(int j=1; j <max_j; j++){
                if(matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                else
                    dp[i][j] = 0;
                if(max_edge < dp[i][j])
                    max_edge = dp[i][j];
            }
        }
        return max_edge * max_edge;
    }

    int min(int a, int b, int c){
        if(a > b){
            return (b > c) ? c : b;
        }
        else{
            return (a > c) ? c : a;
        }
    }
};

int main(){
    //vector<vector<char>> ma = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};

}