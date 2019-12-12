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

int solution(vector<int> nums){
    vector<int> dp(nums.size(), -1);
    dp[0] = 0;
    for(int i=0; i < nums.size() - 1; i++){
        if(dp[i] == -1)     // 表示该点不可达
            continue;
        for(int j=1; j <= nums[i]; j++){
            if(i + j < nums.size()){
                if(dp[i + j] == -1)
                    dp[i + j] = dp[i] + 1;
                else
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    return dp[nums.size() - 1];
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