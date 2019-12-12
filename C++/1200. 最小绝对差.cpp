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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> diff(arr.size() - 1);
        int min_d = INT32_MAX;
        for(int i=1; i < arr.size(); i++){
            int j = i - 1;
            diff[j] = arr[i] - arr[j];
            if(min_d > diff[j])
                min_d = diff[j];
        }
        vector<vector<int>> ans;
        for(int i=0; i < diff.size(); i++){
            if(diff[i] == min_d){
                vector<int> temp = {arr[i], arr[i + 1]};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};