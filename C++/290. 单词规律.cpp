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
    map<char, string> list;
    bool wordPattern(string pattern, string str) {
        str = str + " ";
        vector<string> words;
        int j = 0, k = 0, count = 0;
        for(int i=0; i < str.size(); i++){
            if(str[i] == ' '){
                string temp = str.substr(k, i - k);
                words.push_back(temp);
                k = i + 1;
            }
        }
        if(pattern.size() != words.size())
            return false;
        // 用于保存已有映射的string
        set<string> list_;
        for(int i=0; i < words.size(); i++){
            if(list.count(pattern[i])){
                if(list[pattern[i]] != words[i])
                    return false;
            }
            else{
                if(list_.count(words[i]))
                    return false;
                list.insert(map<char, string>::value_type(pattern[i], words[i]));
                list_.insert(words[i]);
            }
        }
        return true;
    }
};

int main(){
    string str = "aa aa aa aa";
    string patt = "aaa";
    Solution a;
    a.wordPattern(patt, str);
}