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
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        vector<int> ans = {nums[0]};
        for(int i=1; i < nums.size(); i++){
            if(nums[i] > ans[ans.size() - 1]){
                ans.push_back(nums[i]);
                if(ans.size() >= 3)
                    return true;
            }
            else{
                if(ans.size() == 1)
                    ans[0] = nums[i];
                if(ans.size() == 2){
                    if(ans[0] < nums[i])
                        ans[1] = nums[i];
                    else
                        ans[0] = nums[i];
                }
            }
        }
        return false;
    }
};