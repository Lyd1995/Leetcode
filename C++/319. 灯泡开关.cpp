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
    int bulbSwitch(int n) {
        vector<int> dp(n + 1, 0);
        for(int i=1; i <= n; i++){
            if(isAdd(i))
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }

    bool isAdd(int n){
        set<int> list = {1, n};
        int len = int(pow(n, 0.5)) + 1;
        for(int i=2; i <= len; i++){
            if(n % i == 0){
                list.insert(i);
                list.insert(n/i);
            }
        }
        if(list.size() % 2 == 1)
            return true;
        return false;
    }
};

int main(){
    Solution a;
    a.bulbSwitch(5);
}