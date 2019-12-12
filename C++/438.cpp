#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        // dp[i]:表示 从字符串s的第i个字符开始算起，往前dp[i]个字符，都能在字符串p中找到
        vector<int> ans;
        vector<int> dp(s.size(), 0);
        if(p.size() > s.size())
            return ans;
        
        int p_len = p.size();
        // sort(p.begin(), p.end());
        string p1 = p;
        if(isMatch(p, s[0]))
            dp[0]++;
        if(dp[0] == p_len){
            int num = 0;
            ans.push_back(num);
            p = p + s[num];
        }

        for(int i=1; i < s.size(); i++){
            if(isMatch(p, s[i])){
                dp[i] = (dp[i - 1] == p_len) ? (p_len) : (dp[i - 1] + 1);
                if(dp[i] == p_len){
                    int num = i - p_len + 1;
                    ans.push_back(num);
                    p = p + s[num];
                }
            }
            else{
                // 不匹配，两种可能：
                //（1） s[i]在字符串p中，因为之前的操作，去掉了
                //（2） s[i]不在字符串中
                if(dp[i - 1] != 0){
                    int begin = i - dp[i - 1];
                    int j = begin;
                    // 从被删除的字符串中，从前往后寻找第一个与s[i]相等的字符
                    while(j < i && s[j] != s[i])
                        j++;
                    if(j == i){     // 没有找到，s[i]不存在于p中
                        p = p1;
                        dp[i] = 0;
                    }
                    else{           // 找到了，从s[j]开始起的字符串直到s[i]，都能存在于p
                        dp[i] = i - j;
                        if(dp[i - 1] != p_len)
                            p = p + s.substr(begin, j - begin);
                    }
                }
                else{
                    p = p1;
                    dp[i] = 0;
                }
            }
        }
        return ans;
    }

    // 判断是否匹配，匹配则删除
    bool isMatch(string& s, char c){
        for(int i=0; i < s.size(); i++){
            if(s[i] == c){
                s.erase(s.begin() + i, s.begin() + i + 1);
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // dp[i]:表示 从字符串s的第i个字符开始算起，往前dp[i]个字符，都能在字符串p中找到
        vector<int> ans;
        vector<int> dp(s.size(), 0);
        vector<int> flag(p.size(), 1);
        vector<int> flag1(p.size(), 1);
        int pos;
        if(p.size() > s.size())
            return ans;
        
        int p_len = p.size();
        sort(p.begin(), p.end());

        pos = isMatch(p, s[0], flag);
        if(pos != -1)
            dp[0]++;
        if(dp[0] == p_len){
            int num = 0;
            ans.push_back(num);
            flag[0] = 1;
        }

        for(int i=1; i < s.size(); i++){
            pos = isMatch(p, s[i], flag);
            if(pos != -1){
                dp[i] = (dp[i - 1] == p_len) ? (p_len) : (dp[i - 1] + 1);
                if(dp[i] == p_len){
                    int num = i - p_len + 1;
                    ans.push_back(num);
                    int j = 0;
                    while(p[j] != s[num])
                        j++;
                    flag[j] = 1;
                }
            }
            else{
                // 不匹配，两种可能：
                //（1） s[i]在字符串p中，因为之前的操作，去掉了
                //（2） s[i]不在字符串中
                if(dp[i - 1] != 0){
                    int begin = i - dp[i - 1];
                    int j = begin;
                    // 从被删除的字符串中，从前往后寻找第一个与s[i]相等的字符
                    while(j < i && s[j] != s[i])
                        j++;
                    if(j == i){     // 没有找到，s[i]不存在于p中
                        flag = flag1;
                        dp[i] = 0;
                    }
                    else{           // 找到了，从s[j]开始起的字符串直到s[i]，都能存在于p
                        dp[i] = i - j;
                        string sub_s = s.substr(begin, j - begin);
                        modifiedFlag(flag, p, sub_s);
                    }
                }
                else{
                    flag = flag1;
                    dp[i] = 0;
                }
            }
        }
        return ans;
    }

    // 判断是否匹配，匹配则删除
    int isMatch(string& s, char& c, vector<int>& flag){
        for(int i=0; i < s.size(); i++){
            if(s[i] > c)
                break;
            if(s[i] == c && flag[i] == 1){
                flag[i] = 0;
                return i;
            }
        }
        return -1;
    }

    // 修改标记位
    void modifiedFlag(vector<int>& flag, string& p, string& sub_s){
        for(int i=0; i < sub_s.size(); i++){
            int j=0;
            while(p[j] != sub_s[i] || flag[j] == 1)
                j++;
            flag[j] = 1;
        }
    }
};

int main(){
    string s = "abacbabc", p = "abc";
    Solution a;
    vector<int> ans = a.findAnagrams(s, p);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
