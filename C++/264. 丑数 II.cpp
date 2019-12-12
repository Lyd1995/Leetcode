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

class Solution1 {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
        int m = ugly.size() - 1;
        if(n <= m)
            return ugly[n];
        int num = 13;
        while(m < n){
            if(isUglyNum(num))
                m++;
            num++;
        }
        return num - 1;
    }

    bool isUglyNum(int num){
        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5; 
        if(num == 1)
            return true;
        return false;
    }
};


class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        vector<int> ans = {1};
        // 如果采用数组记录下2 * num[i2]，可以得到升序的能整除2的所有丑数
        // 如果采用数组记录下3 * num[i3]，可以得到升序的能整除3的所有丑数
        int m = 1, i2 = 0, i3 = 0, i5 = 0;
        while(m <= n){
            int num2 = 2 * ans[i2], num3 = 3 * ans[i3], num5 = 5 * ans[i5];
            int temp = min(min(num2, num3), num5);
            if(temp == num2)
                i2++;
            if(temp == num3)
                i3++;
            if(temp == num5)
                i5++;
            ans.push_back(temp);
            m++;
        }
        return ans[n - 1];
    }
};

int main(){
    Solution a;
    a.nthUglyNumber(20);
}