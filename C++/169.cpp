#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2)
            return nums[0];
        int n = nums.size(), max_num = 0, max = 0, temp;
        map<int, int> table;
        for(int i = 0; i < n; i++){
            if(table.count(nums[i]) == 0){
                table.insert(map<int, int>::value_type(nums[i], 1));
                continue;
            }
            temp = ++table[nums[i]];
            if(temp > max){
                max_num = nums[i];
                max = temp;
            }
        }
        return max_num;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0], count = 1;
        for(int i=1; i < nums.size(); i++){
            if(num != nums[i]){
                count--;
                if(count <= 0){
                    num = nums[i + 1];
                }
            }
            else
                count++;
        }
        return num;
    }
};


int main(){
    vector<int> nums = {3,1,3};
    Solution a;
    a.majorityElement(nums);
}