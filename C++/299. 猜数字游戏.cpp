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
#include<stdlib.h>
using namespace std;



class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> list1(10, 0), list2(10, 0);
        for(int i=0; i < secret.size(); i++){
            if(secret[i] == guess[i])
                a++;
            else{
                list1[secret[i] - '0']++;
                list2[guess[i] - '0']++;
            }
        }
        for(int i=0; i < 10; i++){
            b += min(list1[i], list2[i]);
        }
        string t1 = int2str(a), t2 = int2str(b);
        string ans;
        ans = ans + t1 + "A" + t2 + "B";
        return ans;
    }

    string int2str(int num){
        string ans;
        if(num == 0)
            return "0";
        while(num){
            int temp = num % 10;
            char ch = temp + '0';
            ans = ans + ch;
            num /= 10;
        }
        return ans;
    }
};

int main(){
    string s1 = "1807", s2 = "7810";
    Solution a;
    a.getHint(s1, s2);
    return 0;
}