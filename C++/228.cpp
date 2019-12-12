#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i=0; i < nums.size(); i++){
            int j = i;
            while(j + 1 < nums.size()){
                if(long(nums[j + 1]) - long(nums[j]) == 1)
                    j++;
                else
                    break;
            }
            if(i != j){
                string temp = int2str(nums[i]) + "->" + int2str(nums[j]);
                ans.push_back(temp);
                i = j;
            }
            else
                ans.push_back(int2str(nums[i]));
        }
        return ans;
    }

    string int2str(long num){
        if(num == 0)
            return "0";
        bool neg = false;
        if(num < 0){
            neg = true;
            num = -num;
        }
        string ans;
        while(num){
            char ch = num%10 + '0';
            num /= 10;
            ans = ch + ans;
        }
        if(neg)
            ans = "-" + ans;
        return ans;
    }
};