#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        long nu = numerator, de = denominator;
        bool flag = isNeg(nu, de);
        string part_int = "", part_deci = "", ans = "";
        computeInt(nu, de, part_int);
        // 判断正负号
        if(flag)
            ans = "-" + ans + part_int;
        else
            ans = ans + part_int;
        // 判断是否需要继续循环
        if(nu == 0)
            return ans;
        computeDeci(nu, de, part_deci);
        ans = ans + "." + part_deci;
        return ans;
    }

    bool isNeg(long& a, long& b){
        int flag1 = 0, flag2 = 0;
        if(a < 0){
            a = -a;
            flag1 = 1;
        }
        if(b < 0){
            b = -b;
            flag2 = 1;
        }
        if(flag1 + flag2 == 1)
            return true;
        else
            return false;
    }

    // 计算整数部分
    void computeInt(long& nu, long& de, string& part_int){
        long int_num = nu / de;
        nu -= int_num * de;
        if(int_num != 0){
            while(int_num){
                int temp1 = int_num / 10;
                int temp2 = int_num - temp1 * 10;
                char ch_temp = temp2 + '0';
                part_int = ch_temp + part_int;
                int_num /= 10;
            }
        }
        else{
            char ch_temp = '0';
            part_int += ch_temp;
        }
        return;
    }
    // 计算小数部分
    void computeDeci(long& nu, long& de, string& part_deci){
        map<long, int> list;
        bool cycle = false;
        int i = 0;
        while(nu){
            nu *= 10;   // 生成被除数
            if(list.count(nu) != 0){
                cycle = true;
                break;
            }
            list.insert(map<long, int>::value_type(nu, i));
            // 被除数 小于 除数
            while(nu < de){
                nu *= 10;
                part_deci += "0";
                list.insert(map<long, int>::value_type(nu, i));
                i++;
            }
            int temp = nu / de;
            char ch_temp = temp + '0';
            part_deci += ch_temp;
            nu -= temp * de;
            i++;
        }
        if(cycle){
            part_deci = part_deci + ")";
            int pos = list[nu];
            part_deci.insert(pos, "(");
        }
        return;
    }
};

int main(){
    int a = -2147483648, b = 1;
    Solution c;
    string ans = c.fractionToDecimal(a, b);
    cout << ans.length() << endl;
    return 0;
}