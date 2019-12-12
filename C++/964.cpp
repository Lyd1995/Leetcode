#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    map<long, int> table;
    int leastOpsExpressTarget(int x, int target) {
        num = x;
        return dp(target, 0) - 1;
    }

    // 动态规划
    int dp(int target, int exp){
        int ans;
        if(target == 0){
            ans = 0;
        }
        else if(target == 1){
            ans = cost(exp);
        }
        else {
            int remainder1 = target % num;
            int quotient = target / num;
            int remainder2 = num - remainder1;
            ans = min(remainder2 * cost(exp) + dp(quotient + 1, exp + 1), remainder1 * cost(exp) + dp(quotient, exp + 1));
        }
        return ans;
    }

    int cost(int& i){
        return (i > 0) ? i : 2;
    }
private:
    int num;
};

int main(){
    Solution a;
    int ans = a.leastOpsExpressTarget(2, 125046);

    return ans;
}


