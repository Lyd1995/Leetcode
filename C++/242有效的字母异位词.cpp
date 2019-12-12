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
    bool isAnagram(string s, string t) {
        vector<int> s_num(26, 0), t_num(26, 0);
        for(auto ch : s)
            s_num[ch - 'a']++;
        for(auto ch : t)
            t_num[ch - 'a']++;
        if(s_num == t_num)
            return true;
        return false;
    }
};