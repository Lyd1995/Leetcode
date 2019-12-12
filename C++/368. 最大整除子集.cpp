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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0 || nums.size() == 1)
            return nums;
        // 这里必须注意到：若子集中任意两个数都有这个性质，那么对子集元素a排序之后，若S % an == 0，则S可以加入该子集
        // 因为an % ai == 0, i = 0, 1, 2, ....
        // dp[i]表示，以nums[i]为最大值的符合要求的子集所包含的最大数量
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int max_pos = 0, max_len = 0;
        for(int i = 1; i < nums.size(); i++){
            int max_i = 0;
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] > max_i)
                        max_i = dp[j];
                }
            }
            dp[i] += max_i;
            if(dp[i] > max_len){
                max_len = dp[i];
                max_pos = i;
            }
        }
        // 找出子集
        ans.push_back(nums[max_pos]);
        int j = max_pos;
        for(int i = max_pos - 1; i >= 0; i--){
            if(nums[j] % nums[i] == 0 && dp[i] + 1 == dp[j]){
                ans.push_back(nums[i]);
                j = i;
            }
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};