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

class Solution1 {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int n;
        if(len % 2 == 0)
            n = len / 2;
        else
            n = len / 2 + 1;
        // 奇数位置的元素大于两边的偶数
        vector<int> v1, v2;
        for(int i=0; i < nums.size(); i++){
            if(i % 2 == 0)
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        int j1 = 0, j2 = 0;
        for(int i=0; i < nums.size(); i++){
            if(i % 2 == 0){
                nums[i] = v1[j1];
                j1++;
            }
            else{
                nums[i] = v2[j2];
                j2++;
            }
        }
        return;
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int n;
        if(len % 2 == 0)
            n = len / 2;
        else
            n = len / 2 + 1;
        // 奇数位置的元素大于两边的偶数
        vector<int> v1 = vector<int>(nums.begin(), nums.begin() + n);
        vector<int> v2 = vector<int>(nums.begin() + n, nums.end());
        int j1 = v1.size() - 1, j2 = v2.size() - 1;
        for(int i=0; i < nums.size(); i++){
            if(i % 2 == 0){
                nums[i] = v1[j1];
                j1--;
            }
            else{
                nums[i] = v2[j2];
                j2--;
            }
        }
        return;
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());

        int size = tmp.size();
        int end = size-1, mid = (size+1)/2-1;
            
        for(int i =0;i<size;i++){
            if(i % 2 == 0)
                nums[i] = tmp[mid--];
            else
                nums[i] = tmp[end--];
        }
    }
};