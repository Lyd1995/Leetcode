#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums2) {
        vector<string> str_nums;
        for(int i = 0; i < nums2.size(); i++){
            str_nums.push_back(int2string(nums2[i]));
        }
        // sort(str_nums.begin(), str_nums.end());
        stringSort(str_nums, 0, str_nums.size() - 1);
        if(str_nums[0] == "0")
            return "0";
        string ans = "";
        for(int i = 0; i < str_nums.size(); i++)
            ans = ans + str_nums[i];
        return ans;
    }

    // 闭区间
    void stringSort(vector<string>& nums, int low, int high){
        if(low >= high)
            return;
        int part = partition(nums, low, high);
        stringSort(nums, low, part - 1);
        stringSort(nums, part + 1, high);
    }

    int partition(vector<string>& nums, int low, int high){
        string str = nums[high];
        // nums之中，i之前的string都小于str
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(cmp(nums[j], str)){
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i + 1, high);
        return i + 1;
    }

    void swap(vector<string>& nums, int i, int j){
        string temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // 判断字符串s1是否大于字符串s2
    bool cmp(string s1, string s2){
        int i = 0;
        while(i < s1.size() && i < s2.size()){
            if(s1[i] > s2[i])
                return true;
            if(s1[i] < s2[i])
                return false;
            i++;
        }
        if(s1 + s2 > s2 + s1)
            return true;
        else
            return false;    
    }

    string int2string(int num){
        if(num == 0)
            return "0";
        string ans = "";
        while(num){
            int temp = num % 10;
            char ch = temp + '0';
            ans = ch + ans;
            num /= 10;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {93,51,65,84,91,78,99,71,97,9};
    Solution a;
    a.largestNumber(nums);
    //string s1="213", s2="2130";
    //bool b = s1 > s2;
}

/*

 */
