#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return (nums[0] > nums[1]) ? nums[0] : nums[1];
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        bool flag = false;
        while(i <= j){
            if(nums[i] > nums[i + 1]){
                ans = i;
                break;
            }
            if(nums[j] > nums[j - 1]){
                ans = j;
                break;
            }
            i++;
            j--;
        }
        return ans;       
    }
};

int main(){
    return 0;
}