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
    int ans;
    vector<vector<int>> flag;
    int closedIsland(vector<vector<int>>& grid) {
        ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> v;
        flag = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(grid[i][j] == 0 && flag[i][j] == 0 && dfs(grid, i, j, n, m)) {
                    ans++;
                    cout << "第" << ans << "个岛屿的坐标：（" << i << " , " << j << "）" << endl; 
                }
            }
        }
        v;
        return ans;
    }

    // dfs：遍历大陆
    bool dfs(vector<vector<int>>& grid, int ri, int ci, int& n, int& m){
        if(isEdge(ri, ci, n, m)){
            flag[ri][ci] = 1;
            return false;
        }
        if(flag[ri][ci] == 0){
            flag[ri][ci] = 1;
            bool f[5] = {true, true, true, true, true};
            int j = 0;
            for(int i=-1; i < 2; i+=2){
                if(ri + i < n && ri + i >= 0 && grid[ri + i][ci] == 0)
                    f[j++] = dfs(grid, ri + i, ci, n, m);
                if(ci + i < m && ci + i >= 0 && grid[ri][ci + i] == 0)
                    f[j++] = dfs(grid, ri, ci + i, n, m);
            }
            bool ans = f[0] && f[1] && f[2] && f[3];
            return ans;
        }
        return true;
    }

    // 判断某一坐标是否为边缘
    bool isEdge(int& ri, int& ci, int& n, int& m){
        if(ri == 0 || ci == 0 || ri == n - 1 || ci == m - 1)
            return true;
        return false;
    }

};

int main(){

    vector<vector<int>> v = {{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};
    Solution a;
    int ans = a.closedIsland(v);

    return ans;
}