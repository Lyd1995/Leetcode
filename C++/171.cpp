#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        long weight = 1;
        int sum = 0;
        for(int i = s.size() - 1;i >= 0; i++){
            sum += (s[i] - 'A' + 1) * weight;
            weight *= 26;
        }
        return sum;
    }
};