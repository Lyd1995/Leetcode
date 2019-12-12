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
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if(input.empty())
            return ans;
        for(int i=0; i < input.size(); i++){
            if(input[i] < '0' || input[i] > '9'){
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for(auto l : left){
                    for(auto r : right){
                        if(input[i] == '+')
                            ans.push_back(l + r);
                        else if(input[i] == '-')
                            ans.push_back(l - r);
                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }
        if(ans.empty())
            ans.push_back(stoi(input));
        return ans;
    }
};
  