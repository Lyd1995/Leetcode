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
    int findDuplicate(vector<int>& nums) {
        vector<int> list(nums.size(), 0);
        for(int i=0; i < nums.size(); i++){
            list[nums[i]]++;
            if(list[nums[i]] > 1)
                return nums[i];
        }
        return 0;
    }
};