#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans, op1, op2;
        // 去除空格
        for(int i=0; i < s.size(); i++){
            if(s[i] == ' '){
                s.erase(i, 1);
                i--;
            }
        }
        int begin = 0;
        ans = computeNum(s, begin);
        return ans;
    }

    // 计算表达式
    long computeNum(string& s, int& i, bool sub=false){
        long ans;
        for(; i < s.size(); i++){
            if(s[i] == '+'){ 
                i++;
                ans = ans + computeNum(s, i);
            }
            else if(s[i] == '-'){
                i++;
                ans = ans + computeNum(s, i, true);
            }
            else if(s[i] == '/'){
                i++;
                ans = ans / char2num(s, i);
            }
            else if(s[i] == '*'){
                i++;
                ans = ans * char2num(s, i);
            }
            else{
                if(sub)
                    ans = -char2num(s, i);
                else
                    ans = char2num(s, i);
            }
        }
        return ans;
    }

    // 从当前字符开始，计算直到遇到第一个操作符为止的数字字符转为数字
    long char2num(string& s, int& i){
        long num = 0;
        for(; i < s.size(); i++){
            if(s[i] < '0' || s[i] > '9')
                break;
            num = num * 10 + s[i] - '0';
        }
        i--;
        return num;
    }
};

int main(){
    string s="  30";
    Solution a;
    a.calculate(s);
}

/*
int op2 = char2num(_s), ans = 0;
        while(!_s.empty()){
            char ch_temp = _s.front();
            _s.pop();
            if(ch_temp == ' '){
                continue;
            }
            else if(char2num(_s) == '+'){
                ans += op2 + char2num(_s);
            }
            else if(char2num(_s) == '-'){
                ans += char2num(_s) - op2;
            }
            else if(char2num(_s) == '*'){
                ans += char2num(_s) * op2;
            }
            else if(char2num(_s) == '/'){
                ans += char2num(_s) / op2;
            }
        }
 */