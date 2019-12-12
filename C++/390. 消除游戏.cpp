#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<math.h>
using namespace std;

// 暴力法
class Solution1 {
public:
    int lastRemaining(int n) {
        vector<int> arr(n + 1, 1);
        double a = log(n) / log(2);
        int num = n, k, count;
        cout << "被剔除的数字：" << endl;
        while(num != 1){
            k = 1;
            count = 0;
            for(int i=1; i <= n; i++){
                if(arr[i]){
                    if(k){
                        arr[i] = 0;
                        k = 0;
                        num--;
                        count++;
                        cout << i << " ";
                    }
                    else
                        k++;
                }
            }
            cout << "\n剔除了" << count << "个数字\n" << endl;
            if(num == 1)
                break;
            k = 1;
            count = 0;
            for(int i=n; i > 0; i--){
                if(arr[i]){
                    if(k){
                        arr[i] = 0;
                        k = 0;
                        num--;
                        count++;
                        cout << i << " ";
                    }
                    else
                        k++;
                }
            }
            cout << "\n剔除了" << count << "个数字\n" << endl;
        }
        for(int i=1; i <= n; i++)
            if(arr[i])
                return i;
        return 0;
    }
};

// 
class Solution {
public:
    int lastRemaining(int n) {
        return solve(n);        
    }

    int solve(int n){
        if(n == 1 || n == 2)
            return n;
        if(n % 2)
            n--;
        return n + 2 - 2 * solve(n / 2);
    }
};

int main() {
    Solution a;
    a.lastRemaining(9);
}