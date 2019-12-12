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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // 定义因子指针数组
        vector<int> pointer(primes.size(), 0), nums = {1};
        vector<int> candi(primes.size(), 0);
        for(int i=0; i < n - 1; i++){
            int num = INT32_MAX;
            for(int j=0; j < primes.size(); j++){
                candi[j] = nums[pointer[j]] * primes[j];
                if(candi[j] < num)
                    num = candi[j];
            }
            nums.push_back(num);
            for(int j=0; j < pointer.size(); j++){
                if(num == candi[j])
                    pointer[j]++;
            }
        }
        return nums[n - 1];
    }
};

int main(){

}