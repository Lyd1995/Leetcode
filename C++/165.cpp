#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1.empty() || version2.empty())
            return 0;
        int num1 = 0, num2 = 0;
        while(!version1.empty() || !version2.empty()){
            num1 += extractNum(version1);
            num2 += extractNum(version2);
            if(num1 > num2)
                return 1;
            if(num1 < num2)
                return -1;
        }
        return 0;
    }

    int extractNum(string& s){
        if(s.empty())
            return 0;
        int i = 0, num = 0, temp;
        while(s[i] != '.' && i < s.size()){
            num = num * 10;
            temp = s[i++] - '0';
            num = num + temp;
        }
        if(s[i] == '.')
            s.erase(s.begin(), s.begin() + i + 1);
        else
            s.erase(s.begin(), s.begin() + i);
        return num;
    }
};

int main(){
    string s1="1", s2="0";
    Solution a;
    a.compareVersion(s1, s2);
}