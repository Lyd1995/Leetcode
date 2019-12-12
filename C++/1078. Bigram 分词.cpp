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
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words = cutUp(text, ' ');
        vector<string> ans;
        for(int i=0; i < words.size(); i++){
            if(words[i] == first){
                int j = i + 1;
                if(j < words.size() && words[j] == second){
                    j++;
                    if(j < words.size())
                        ans.push_back(words[j]);
                }
            }
        }
        return ans;
    }

    // s:需要分割的字符串
    // Ident：分割的标识符，一般是：空格、下划线、逗号等
    vector<string> cutUp(string s, char Ident){
        s = s + Ident;
        vector<string> ans;

        for(int i=0; i < s.size(); i++){
            int j = i;
            while(j < s.size() && s[j] == Ident)
                j++;
            i = j;
            while(j < s.size() && s[j] != Ident)
                j++;
            ans.push_back(s.substr(i, j - i));
            i = j;
        }

        return ans;
    }

};