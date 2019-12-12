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
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        for(long long i=1; i <= num; i++){
            long long temp = i * i;
            if(temp == num)
                return true;
            if(temp > num)
                break;
        }
        return false;
    }
};