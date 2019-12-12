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
    void moveZeroes(vector<int>& nums) {
        int num = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                i--;
                num++;
            }
        }
        nums.insert(nums.end(), num, 0);
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // i：指向原数组 
        // j：指向不为0的数组
        int i = 0, j = 0, len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i]){
                nums[j] = nums[i];
                j++;
            }
        }
        for(int i=j; i < len; i++)
            nums[i] = 0;
    }
};