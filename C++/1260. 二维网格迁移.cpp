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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int sum = n * m;
        k = k % sum;
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                int row, col;
                row = i + (j + k) / m;
                col = (j + k) % m;
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};

/*

[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
 */