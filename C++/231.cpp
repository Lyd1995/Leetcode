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
    bool isPowerOfTwo(int n) {
        long n_l = n;
        long m = n_l & (n_l - 1);
        if(m)
            return false;
        return true;
    }
};

int main(){
    Solution a;
    a.isPowerOfTwo(2);
}