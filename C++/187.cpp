#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> ans;
        if(s.size() <= 10)
            return vector<string>();
        map<string, int> table;
        for(int i = 0; i < s.size() - 9; i++){
            string temp = s.substr(i, 10);
            if(table.count(temp) == 0){
                table.insert(map<string, int>::value_type(temp, 1));
                continue;
            }
            ans.insert(temp);
        }
        return vector<string>(ans.begin(), ans.end());
    }
};