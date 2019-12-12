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
#include<stdlib.h>
using namespace std;

int sumNum(vector<int>& v){
    int sum = 0;
    for(auto n : v)
        sum += n;
    return sum;
}

int solution(vector<int> nums){
    if(nums.size() == 1)
        return nums[0];
    int len = nums.size() - 1, sum = sumNum(nums);
    int target = sum / 2, n = len / 2;
    int w1 = 0;
    sort(nums.begin(), nums.end());
    for(int i=0; i < n; i++){
        w1 += nums[i];
    }
    int i1 = 0, j1 = len, w2 = w1;
    while(w1 < target){
        w1 = w1 - nums[i1] + nums[j1];
        i1++;
        j1--;
    }
    int i2 = n - 1, j2 = n;
    while(w2 < target){
        w2 = w2 - nums[i2] + nums[j2];
        i2--;
        j2++;
    }
    int d1 = abs(2 * w1 - sum), d2 = abs(2 * w2 - sum);
    return min(d1, d2);
}


int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    vector<int> nums;
    while(ss >> x)
        nums.push_back(x);
    int num = solution(nums);
    cout << num << endl;
    return 0;
}