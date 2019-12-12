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

// 暴力法
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n, 0);
        vector<string> str_sort(n);
        for(int i=0; i < n; i++)
            str_sort[i] = int2str(i + 1);
        sort(str_sort.begin(), str_sort.end());
        for(int i=0; i < str_sort.size(); i++)
            ans[i] = str2int(str_sort[i]);
        return ans;
    }

    int str2int(string s){
        long long ans = 0;
        for(int i=0; i < s.size(); i++){
            ans = ans * 10 + s[i] - '0';
        }
        return ans;
    }

    string int2str(int num){
        if(num == 0)
            return "0";
        string ans = "";
        while(num){
            char temp = num % 10 + '0';
            ans = temp + ans;
            num /= 10;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(n, ans, 0);
        return ans;
    }

    void dfs(int& n, vector<int> &ans, int num){
        if(num > n)
            return;
        if(num != 0)
            ans.push_back(num);
        for(int i=0; i < 10; i++){
            if(num * 10 + i > 0)
                dfs(n, ans, num * 10 + i);
        }
    }
};