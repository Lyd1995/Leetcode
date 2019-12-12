
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
    int rangeBitwiseAnd(int m, int n) {
        uint32_t sum = 0;
        int i = 32;
        uint32_t mt = m, nt = n;
        while(i--){
            uint32_t temp = 1;
            uint32_t n2 = nt;
            while(n2 >= mt){
                if(mt == 0 || n2 % 2 == 0){
                    temp = 0;
                    break;
                }
                n2--;
            }
            sum <<= 1;
            sum = sum + temp;
            mt >>= 1;
            nt >>= 1;
        }
        i = 32;
        uint32_t ans = 0;
        while(i--){
            ans <<= 1;
            uint32_t temp = sum & 1;
            ans = ans + temp;
            sum >>= 1;
        }
        return ans;
    }
};



class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = m;
        while(n >= m){
            m++;
            ans = ans & m;
        }
        return ans;
    }
};


int main(){
    Solution a;
    a.rangeBitwiseAnd(7, 21);
}