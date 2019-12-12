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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0)
            return m * n;
        // 最大元素为（0,0）
        int row = INT32_MAX, col = INT32_MAX;
        for(int i=0; i < ops.size(); i++) {
            row = min(row, ops[i][0]);
            col = min(col, ops[i][1]);
        }
        return row * col;
    }
};