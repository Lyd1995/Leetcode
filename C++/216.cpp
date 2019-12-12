#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k > 9)
            return ans;
        
        int minnum = (k + 1) * k / 2, maxnum = 45 - (10 - k) * (9 - k) / 2;
        if(n < minnum || n > maxnum)
            return ans;
        vector<int> nums;
        int sum = 0;
        trackBack(k, n, ans, nums, 1, sum);
        return ans;
    }

    void trackBack(int k, int n, vector<vector<int>>& ans, vector<int>& nums, int pre_num, int& sum){
        if(nums.size() == k){
            if(sum == n)
                ans.push_back(nums);
            return;
        }
        for(int i=pre_num; i < 10; i++){
            if(sum >= n)
                return;
            sum += i;
            nums.push_back(i);
            trackBack(k, n, ans, nums, i + 1, sum);
            sum -= i;
            nums.pop_back();
        }
    }
};

int main(){
    Solution a;
    a.combinationSum3(3, 7);
}