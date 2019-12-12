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
    int addDigits(int num) {
        int n = 0, temp;
        while(num != 0){
            temp = num % 10;
            num /= 10;
            n += temp;
            if(num == 0 && n > 9){
                num = n;
                n = 0;
            }
        }
        return n;
    }
};