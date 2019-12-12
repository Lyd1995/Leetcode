#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
       return (n == 0) ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

int main(){
    Solution a;
    a.trailingZeroes(3565641152);
}