#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


class Solution {
public:
    bool rotateString(string A, string B) {
        int len = A.size();
        while(len--) {
            if(A == B)
                return true;
            char t = A[0];
            A.erase(0, 1);
            A = A + t;
        }
        return false;
    }
};

int main() {
    string a = "abcde", b = "cdeab";
    Solution sol;
    sol.rotateString(a, b);

    return 0;
}