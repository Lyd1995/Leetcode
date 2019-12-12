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
    int longestPalindrome(string s) {
        map<char, int> hash;
        for(auto ch : s)
            hash[ch]++;
        int ans = 0, max_single = 0;
        bool f = false;
        for(auto i : hash){
            if(i.second % 2 == 0)
                ans += i.second;
            else{
                ans += i.second - 1;
                f = true;
            }
        }
        if(f)
            ans++;
        return ans;
    }
};