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
    int countSegments(string s) {
        int ans = 0;
        for(int i=0; i < s.size(); i++){
            while(i < s.size() && s[i] == ' ')
                i++;
            if(i < s.size())
                ans++;
            while(i < s.size() && s[i] != ' ')
                i++;
        }
        return ans;
    }
};