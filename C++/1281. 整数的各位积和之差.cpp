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

class Solution {
public:
    int subtractProductAndSum(int n) {
        int ans, sum = 0, acc = 1;
        vector<int> nums;
        helper(n, nums);
        for(int i=0; i < nums.size(); i++){
            sum += nums[i];
            acc *= nums[i];
        }
        ans = acc - sum;
        return ans;
    }

    void helper(int n, vector<int>& nums){
        if(n == 0){
            nums.push_back(0);
            return;
        }
        while(n != 0){
            nums.push_back(n % 10);
            n /= 10;
        }
        return;
    }
};