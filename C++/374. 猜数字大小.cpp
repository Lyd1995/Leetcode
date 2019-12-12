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

int guess(int num){
    if(num > 6)
        return 1;
    if(num < 6)
        return -1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int mid = (n + 1) / 2, low = 1, high = n;
        int ans = guess(mid);
        while(ans != 0){
            if(ans < 0){
                low = mid;
            }
            else{
                high = mid;
            }
            mid = (high + low) / 2;
            ans = guess(mid);
        }
        return mid;
    }
};