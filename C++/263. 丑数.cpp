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
    bool isUgly(int num) {
        if(num < 1)
            return false;
        if(num == 1)
            return true;
        int n;
        while(num){
            n = num;
            if(num % 2 == 0)
                num /= 2;
            if(num % 3 == 0)
                num /= 3;
            if(num % 5 == 0)
                num /= 5;
            if(num == 1)
                return true;
            if(n == num)
                return false;
        }
        return false;
    }
};