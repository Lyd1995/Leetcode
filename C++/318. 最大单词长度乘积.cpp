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
    vector<vector<int>> table;
    int maxProduct(vector<string>& words) {
        int ans = 0;
        table = vector<vector<int>>(words.size(), vector<int>(26, 0));
        initial(words);
        for(int i=0; i < words.size(); i++){
            for(int j=i+1; j < words.size(); j++){
                int pro = words[i].size() * words[j].size();
                if(pro > ans)
                    if(isDifferent(i, j))
                        ans = pro;
            }
        }
        return ans;
    }

    bool isDifferent(int& i, int& j){
        for(int k=0; k < 26; k++){
            if(table[i][k] > 0 && table[j][k] > 0)
                return false;
        }
        return true;
    }

    void initial(vector<string>& words){
        for(int i=0; i < words.size(); i++){
            for(auto ch : words[i])
                table[i][ch - 'a']++;
        }
    }
};