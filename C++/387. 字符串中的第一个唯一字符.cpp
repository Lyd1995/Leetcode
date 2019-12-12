#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<math.h>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ch(26, 0);
        for(int i=0; i < s.size(); i++){
            ch[s[i] - 'a']++;
        }
        for(int i=0; i < s.size(); i++){
            if(ch[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};