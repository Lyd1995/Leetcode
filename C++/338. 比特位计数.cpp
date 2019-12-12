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
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0; i <= num; i++){
            ans.push_back(solve(i));
        }
        return ans;
    }

    int solve(int num){
        int ans = 0;
        while(num){
            ans += num & 1;
            num = num >> 1;
        }
        return ans;
    }
};

int main(){
    Solution a;

}