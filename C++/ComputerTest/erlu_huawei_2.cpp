#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A(2 * n);
    for(int i=0; i < 2 * n; i++){
        int temp;
        cin>>temp;
        A[i] = temp;
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(A[0] == A[0 + n])
        dp[0][0] = 1;
    else
        dp[0][0] = 0;
    for(int i=1; i < n; i++){
        if(A[i] == A[0 + n])
            dp[i][0] = 1;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for(int j=1; j < n; j++){
        if(A[0] == A[j + n])
            dp[0][j] = 1;
        else
            dp[0][j] = dp[0][j - 1];
    }
    // 计算
    for(int i=1; i < n; i++){
        for(int j=1; j < n; j++){
            if(A[i] == A[j + n])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int ans = n - dp[n - 1][n - 1];
    cout<<ans;
    return 0;
}