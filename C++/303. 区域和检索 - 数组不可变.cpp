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

class NumArray {
public:
    NumArray(vector<int>& nums) {
        // dp[i] = sum (nums[0] + .... nums[i - 1])
        dp = vector<int>(nums.size() + 1, 0);
        for(int i=0; i < nums.size(); i++){
            dp[i + 1] = dp[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */