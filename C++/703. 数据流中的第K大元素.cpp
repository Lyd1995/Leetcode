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

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        my_nums = vector<int>(nums);
        my_k = k;
        sort(my_nums.rbegin(), my_nums.rend());
    }
    
    int add(int val) {
        bool flag = true;
        for(int i=0; i < my_nums.size(); i++){
            if(val > my_nums[i]){
                my_nums.insert(my_nums.begin() + i, val);
                flag = false;
                break;
            }
            if(i > my_k)
                break;
        }
        if(flag)
            my_nums.push_back(val);
        return my_nums[my_k - 1];
    }
private:
    vector<int> my_nums;
    int my_k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */