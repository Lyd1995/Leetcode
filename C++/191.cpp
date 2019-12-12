#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int i = 32;
        while(i--){
            if(n&1 == 1)
                count++;
            n = n >> 1;
        }
        return count;
    }
};