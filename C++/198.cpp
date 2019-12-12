#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

struct node{
    int val, pos;
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.empty())
            return 0;
        // 设dp1[i]表示当前nums[i]之前（可以包括nums[i]），可获得的最高金额
        // 设dp2[i]表示当前nums[i]之前（不包括nums[i]），可获得的最高金额
        vector<int> dp(nums.size(), 0), flag(nums.size(), 0);
        dp[0] = nums[0];
        if(nums[1] > nums[0]){
            dp[1] = nums[1];
            flag[1] = 1;
        }
        else
            dp[1] = nums[0];
        for(int i = 2; i < nums.size(); i++){
            if(flag[i - 1] == 1) {  // 使用了 nums[i - 1]
                if(dp[i - 2] + nums[i] > dp[i - 1]){
                    dp[i] = dp[i - 2] + nums[i];
                    flag[i] = 1;
                }
                else{
                    dp[i] = dp[i - 1];
                }
            }
            else{
                dp[i] = dp[i - 1] + nums[i];
                flag[i] = 1;
            }
        }
        return dp[nums.size() - 1];
    }

};

class Solution1 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.empty())
            return 0;
        vector<node> table;
        for(int i=0; i < nums.size(); i++){
            node ni;
            ni.val = nums[i];
            ni.pos = i;
            table.push_back(ni);
        }
        sort_node(table, 0, table.size() - 1);
        set<int> isadjacent;
        int ans = 0;
        for(int i=0; i < table.size(); i++){
            int pos = table[i].pos;
            int left = pos - 1, right = pos + 1;
            if(isadjacent.count(left) == 0 && isadjacent.count(right) == 0){
                ans += table[i].val;
                isadjacent.insert(pos);
            }
        }
        return ans;
    }

    void sort_node(vector<node>& table, int begin, int end){
        if(begin >= end)
            return;
        int part = partition(table, begin, end);
        sort_node(table, begin, part - 1);
        sort_node(table, part + 1, end);
    }

    int partition(vector<node>& table, int begin, int end){
        int x = table[end].val;
        int i = begin - 1;
        for(int j = begin; j < end; j++){
            if(table[j].val > x){
                i++;
                swap(table, i, j);
            }
        }
        swap(table, i + 1, end);
        return i + 1;
    }

    void swap(vector<node>& table, int a, int b){
        node temp = table[a];
        table[a] = table[b];
        table[b] = temp;
    }
};

int main(){
    vector<int> nums = {1,3,1,3,100};
    Solution a;
    a.rob(nums);
}