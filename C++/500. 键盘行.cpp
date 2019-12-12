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
    vector<string> findWords(vector<string>& words) {
        set<char> line1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> line2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<char> line3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> ans;
        for(auto s : words){
            if(s == "") {
                ans.push_back(s);
                continue;
            }
            char ch = s[0];
            if(line1.count(ch)){
                if(helper(s, line1) || line1.count(ch + 32))
                    ans.push_back(s);
            }
            else if(line2.count(ch) || line2.count(ch + 32)){
                if(helper(s, line2))
                    ans.push_back(s);
            }
            else if(line3.count(ch) || line3.count(ch + 32)){
                if(helper(s, line3))
                    ans.push_back(s);
            }
        }
        return ans;
    }

    bool helper(string s, set<char>& line){
        cout << "string : " << s << endl;
        for(auto ch : s){
            if(line.count(ch) || line.count(ch + 32)){
                cout << ch << " ";
                continue;
            }
            cout << endl;
            return false;
        }
        cout << endl;
        return true;
    }
};