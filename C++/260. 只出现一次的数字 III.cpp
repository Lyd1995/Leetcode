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
    vector<int> singleNumber(vector<int>& nums) {
        set<int> ans;
        for(int i=0; i < nums.size(); i++){
            if(ans.count(nums[i]) == 0){
                ans.insert(nums[i]);
                continue;
            }
            if(ans.count(nums[i]))
                ans.erase(nums[i]);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};