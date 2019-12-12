#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < s.size() && !isVowel(s[i]))
                i++;
            while(j >= 0 && !isVowel(s[j]))
                j--;
            if(i >= j)
                break;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u')
            return true;
        if(ch == 'A' || ch == 'E' || ch == 'O' || ch == 'I' || ch == 'U')
            return true;
        return false;
    }
};