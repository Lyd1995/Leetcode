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
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n + 1) * n / 2;
        for(int i=0; i < nums.size(); i++)
            sum -= nums[i];
        return sum;
    }
};