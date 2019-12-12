#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


class Solution2 {
public:
    string convertToTitle(int n) {
        //先确定低位，从低到高：
        string ans = "";
        long weight = 1;
        int offset = 'A' - 1;
        while(n > 26){
            int temp = n % 26;
            if(temp == 0){
                int mul = n / weight;
                if(mul < 27){
                    char ch_temp = mul + offset;
                    ans = ch_temp + ans;
                    n = 0;
                    break;
                }
                else{
                    ans = "Z" + ans;
                    n = n - 26 * weight;
                }
            }
            else{
                char ch_temp = temp + offset;
                ans = ch_temp + ans;
                n = n - weight * temp;
            }
            weight = weight * 26;
        }
        if(n){
            char ch = n + offset;
            ans = ch + ans;    
        }
        return ans;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        //先确定低位，从低到高：
        string ans = "";
        long weight = 1;
        int offset = 'A' - 1;
        while(true){
            // temp:计算当前最低位的数值，0～A，1～B.......
            int temp = n % (26 * weight);
            temp = temp / weight;
            char ch_temp;
            if(temp != 0)
                ch_temp = temp + offset;
            else
                ch_temp = 'Z';
            ans = ch_temp + ans;
            n = n - weight * (ch_temp - offset);
            if(n < weight)
                break;
            weight = weight * 26;
        }
        return ans;
    }
};

int main(){
    Solution a;
    a.convertToTitle(52);
}