#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0)
            return false;
        if(num & (num - 1) != 0)
            return false;
        if((num & 0x55555555) == num)
            return true;
        return false;
    }
};