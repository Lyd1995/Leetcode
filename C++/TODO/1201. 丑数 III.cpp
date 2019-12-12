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
    int nthUglyNumber(int n, int a, int b, int c) {
        int min_num = min(a, min(b, c)), mid_num, max_num = max(a, max(b, c));
        mid_num = (a - min_num) + (b - max_num) + c;
        int m1 = computeNum(min_num, mid_num), m2 = computeNum(min_num, max_num), m3 = computeNum(mid_num, max_num);
        if(n <= m1)
            return n * min_num;
        if(n == m1 + 1)
            return mid_num;
        if(n <= m2 + m3){
            if(mid_num % min_num == 0){
                return n * min_num;
            }
            else{
                int m = 2;
                int temp = m - 1 + computeNum(min_num, m * mid_num);
                while(temp < n){
                    m++;
                    temp = m - 1 + computeNum(min_num, m * mid_num);
                }
                int n1 = computeNum(min_num, (m - 1) * mid_num), n2 = m - 1;
                int count = n1 + n2, num1, num2, num;
                while(true){
                    num1 = n1 * min_num;
                    num2 = n2 * mid_num;
                }
            }
        }
        if(n == m2 + m3 + 1)
            return max_num;
        
    }

    // 计算[0, b)区间内，a的倍数有多少
    int computeNum(int a, int b){
        int m = b / a;
        if(b % a == 0)
            return m - 1;
        return m;
    }
};

/*
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int min_num = min(a, min(b, c)), mid_num, max_num = max(a, max(b, c));
        mid_num = (a - min_num) + (b - max_num) + c;
        int m1 = mid_num / min_num, m2 = max_num / min_num, m3 = max_num / mid_num;
        // 前m个数必定为min_d的整数倍
        if(n <= m1)
            return m1 * min_num;
        else if(n <= m2 + m3){
            int n1 = m1 + 1, n2 = 1;
            int count = m1, num, num1, num2;
            while(true){
                num1 = n1 * min_num;
                num2 = n2 * mid_num;
                num = min(num1, num2);
                count++;
                if(num == num1)
                    n1++;
                if(num == num2)
                    n2++;
                if(count == n)
                    break;
            }
            return num;
        }
        int n1 = m2 + 1, n2 = m3 + 1, n3 = 1;
        int count = m2 + m3, num, num1, num2, num3;
        while(true){
            num1 = n1 * min_num;
            num2 = n2 * mid_num;
            num3 = n3 * max_num;
            num = min(num1, min(num2, num3));
            count++;
            if(num == num1)
                n1++;
            if(num == num2)
                n2++;
            if(num == num3)
                n3++;
            if(count == n)
                break;
        }
        return num;
    }
};
 */


int main(){
    Solution a;
    auto c = a.nthUglyNumber(6, 2, 11, 13);
    return 0;
}

/*
1000000000
2
217983653
336916467
 */