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
    bool isAdditiveNumber(string num) {
        int i1 = 0, len = num.size();
        bool flag = false;
         for(int len1=1; len1 < len; len1++){
            string s1 = num.substr(i1, len1);
            if(s1[0] == '0' && len1 > 1)
                break;
            for(int len2=1; len2 < len; len2++){
                int i2 = i1 + len1;
                string s2 = num.substr(i2, len2);
                if(s2[0] == '0' && len2 > 1)
                    break;
                string sum = addString(s1, s2);
                int len3 = sum.size(), i3 = i2 + len2;
                if(i3 + len3 > num.size())
                    break;
                string s3 = num.substr(i3, len3);
                if(sum == s3){
                    flag = dfs(num, s2, s3, i3 + len3);
                }
                if(flag)
                    return flag;
            }
        }       
        return false;
    }

    bool dfs(string& num, string& s1, string& s2, int i3){
        if(i3 == num.size())
            return true;
        string sum = addString(s1, s2);
        int len3 = sum.size();
        if(i3 + len3 > num.size())
            return false;
        string s3 = num.substr(i3, len3);
        if(s3 == sum)
            return dfs(num, s2, s3, i3 + len3);
        else
            return false;
    }

    string addString(string& s1, string& s2){
        string ans;
        int i = s1.size() - 1, j = s2.size() - 1;
        int carry = 0, p;
        while(i >= 0 && j >= 0){
            int t1 = s1[i] - '0', t2 = s2[j] - '0';
            int temp = t1 + t2 + carry;
            carry = temp / 10;
            p = temp % 10;
            char ch = p + '0';
            ans = ch + ans;
            i--;
            j--;
        }
        while(i >= 0){
            int t1 = s1[i] - '0';
            int temp = t1 + carry;
            carry = temp / 10;
            p = temp % 10;
            char ch = p + '0';
            ans = ch + ans;
            i--;
        }
        while(j >= 0){
            int t2 = s2[j] - '0';
            int temp = t2 + carry;
            carry = temp / 10;
            p = temp % 10;
            char ch = p + '0';
            ans = ch + ans;
            j--;
        }
        if(carry){
            char ch = carry + '0';
            ans = ch + ans;
        }
        return ans;
    }
};

int main(){
    string s = "199001200";
    Solution a;
    a.isAdditiveNumber(s);
    return 0;
}