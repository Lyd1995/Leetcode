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
    int superPow(int a, vector<int>& b) {
        int mod = 1337, ans = 1;
        for(int i=0; i < b.size(); i++){
            long t1 = powAndMod(ans, 10, mod), t2 = powAndMod(a, b[i], mod);
            long temp = (t1 * t2) % mod;
            ans = temp;
        }
        return ans;
    }

    long powAndMod(long a, long exp, long mod){
        long a1 = a % mod;
        long ans = 1;
        while(exp--){
            ans *= a1;
            ans = ans % mod;
        }
        return ans;
    }
};