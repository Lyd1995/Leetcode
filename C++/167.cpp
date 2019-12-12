#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        if(numbers.size() == 0 || numbers.size() == 1)
            return ans;

        int i = 0, j = numbers.size() - 1, sum;
        while(i < j){
            sum = numbers[i] + numbers[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(sum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};