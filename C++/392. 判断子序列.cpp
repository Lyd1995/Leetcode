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
    bool isSubsequence(string s, string t) {
        int pre = 0;
        bool ans = true;
        for(auto ch_s : s){
            bool flag = true;
            for(int i=pre; i < t.size(); i++) {
                if(ch_s == t[i]){
                    flag = false;
                    pre = i + 1;
                    break;
                }
            }
            if(flag) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};