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
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ran(26, 0), mag(26, 0);
        // 建立映射
        for(int i=0; i < ransomNote.size(); i++)
            ran[ransomNote[i] - 'a']++;
        for(int i=0; i < magazine.size(); i++)
            mag[magazine[i] - 'a']++;
        // 判断
        for(int i=0; i < 26; i++){
            if(ran[i] > mag[i])
                return false;
        }
        return true;
    }
};