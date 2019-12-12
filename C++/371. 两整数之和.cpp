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
    int getSum(int a, int b) {
        
        while (b) {
            auto carry = ((unsigned int) (a & b)) << 1 ; // 记录a+b的进位，直到进位为0是退出
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "carry = " << carry << endl;
            cout << endl;
            a = a ^ b;      //结果相加
            b = carry;      //循环
        }
        return a;
    }
};

int main(){
    Solution a;
    a.getSum(-2, 3);
    getchar();
}