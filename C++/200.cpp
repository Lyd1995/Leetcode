#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int max_x = grid.size(), max_y = grid[max_x -1].size();
        int count=0;
        for(int i=0; i < max_x; i++){
            for(int j=0; j < max_y; j++){
                if(grid[i][j] == '1' && isIsland(grid, i, j))
                    count++;
            }
        }
        return count;
    }

    bool isIsland(vector<vector<char>>& grid, int x, int y){
        int max_x = grid.size(), max_y = grid[max_x -1].size(), nums = 0;
        if(x + 1 < max_x){
            if(grid[x + 1][y] == '0')
                nums++;
        }
        else
            nums++;

        if(x - 1 >= 0){
            if(grid[x - 1][y] == '0')
                nums++;
        }
        else
            nums++;

        if(y - 1 >= 0){
            if(grid[x][y - 1] == '0')
                nums++;
        }
        else
            nums++;

        if(y + 1 < max_y){
            if(grid[x][y + 1] == '0')
                nums++;
        }
        else
            nums++;

        if(nums > 2)
            return true;
        else
        {
            return false;
        }
        
    }
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int max_x = grid.size(), max_y = grid[max_x -1].size();
    //    vector<vector<bool>> flag(max_x, vector<bool>(max_y, false));
        int count=0;
        for(int i=0; i < max_x; i++){
            for(int j=0; j < max_y; j++){
                if(grid[i][j] == '1' && dfs(grid, i, j))
                    count++;
            }
        }
        return count;
    }

    bool dfs(vector<vector<char>>& grid, int x, int y){
        int max_x = grid.size(), max_y = grid[max_x -1].size();
        grid[x][y] = '2';
        if(x + 1 < max_x && grid[x + 1][y] == '1')
            dfs(grid, x + 1, y);

        if(x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, x - 1, y);

        if(y + 1 < max_y && grid[x][y + 1] == '1')
            dfs(grid, x, y + 1);

        if(y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, x, y - 1);

        return true;
    }

    bool bfs(vector<vector<char>>& grid, int x, int y){
        queue<pair<int, int>> qu;
        int max_x = grid.size(), max_y = grid[max_x -1].size();
        qu.push(pair<int, int>(x, y));
        while(!qu.empty()){
            int len = qu.size();
            for(int i=0; i < len; i++){
                pair<int, int> temp = qu.front();
                qu.pop();
                grid[temp.first][temp.second] = '2';

                if(temp.first + 1 < max_x){
                    if(grid[temp.first + 1][temp.second] == '1'){
                        qu.push(pair<int, int>(temp.first + 1, temp.second));
                    }
                }

                if(temp.first - 1 >= 0){
                    if(grid[temp.first - 1][temp.second] == '1'){
                        qu.push(pair<int, int>(temp.first - 1, temp.second));
                    }
                }
                
                if(temp.second + 1 < max_y){
                    if(grid[temp.first][temp.second + 1] == '1'){
                        qu.push(pair<int, int>(temp.first, temp.second + 1));
                    }
                }

                if(temp.second - 1 >= 0){
                    if(grid[temp.first][temp.second - 1] == '1'){
                        qu.push(pair<int, int>(temp.first, temp.second - 1));
                    }
                }
            }
        }
        return true;
    }

    
};