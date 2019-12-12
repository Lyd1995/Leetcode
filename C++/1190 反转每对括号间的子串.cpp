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
    string reverseParentheses(string s) {
        stack<int> left;
        for(int i=0; i < s.size(); i++){
            if(s[i] == '('){
                left.push(i);
                s.erase(i, 1);
                i--;
                continue;
            }
            if(s[i] == ')'){
                int l = left.top();
                left.pop();
                reverse(s.begin() + l, s.begin() + i);
                s.erase(i, 1);
                i--;
                continue;
            }
        }
        return s;
    }
};