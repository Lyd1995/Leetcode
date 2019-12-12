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
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i = 0;
        while(i < s.size() && i < t.size()){
            if(s[i] != t[i])
                return t[i];
            i++;
        }
        return t[i];
    }
};