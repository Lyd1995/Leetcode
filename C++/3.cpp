#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;

struct node{
    int x, y;
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        vector<node> land;
        vector<node> sea;
        int x_max = grid.size(), y_max = grid[x_max - 1].size();
        // 找出所有陆地
        computeLand(grid, land, sea, x_max, y_max);
        int num = land.size(), total_num = x_max * y_max;
        if(num == 0 || num == total_num)
            return -1;
        int ans = computeMaxDistance(grid, land, sea, x_max, y_max);
        return ans;
    }

    void computeLand(vector<vector<int>>& grid, vector<node>& land, vector<node>& sea,int x_max, int y_max){
        for(int i=0; i < x_max; i++){
            for(int j=0; j < y_max; j++){
                if(grid[i][j]){
                    node temp;
                    temp.x = i + 1;
                    temp.y = j + 1;
                    land.push_back(temp);
                }
                else{
                    node temp;
                    temp.x = i + 1;
                    temp.y = j + 1;
                    sea.push_back(temp);
                }
            }
        }
    }

    int computeMaxDistance(vector<vector<int>>& grid, vector<node>& land, vector<node>& sea, int x_max, int y_max){
        int max_d = 0, d;
        node temp;
        for(int i=0; i < sea.size(); i++){
            temp = sea[i];
            d = computeDistance(land, temp.x, temp.y, max_d);
            if(d > max_d)
                max_d = d;
        }
        return max_d;
    }

    int computeDistance(vector<node>& land, int x, int y, int cur_max_d){
        int min_d = INT32_MAX, d;
        node temp;
        for(int i=0; i < land.size(); i++){
            temp = land[i];
            d = abs(temp.x - x) + abs(temp.y - y);
            if(min_d > d)
                min_d = d;
            if(cur_max_d > min_d)
                break;
        }
        return min_d;
    }
};


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        int max_x = grid.size(), max_y = grid[max_x - 1].size();
        queue<pair<int, int>> qu;
        for(int i=0; i < max_x; i++){
            for(int j=0; j < max_y; j++){
                if(grid[i][j] == 1)
                    qu.push(pair<int, int>(i, j));
            }
        }
        if(qu.empty() || qu.size() == max_x + max_y)
            return -1;
        int n = 1;
        while(!qu.empty()){
            pair<int, int> temp = qu.front();
            qu.pop();
            if(temp.first + 1 < max_x && grid[temp.first + 1][temp.second] == 0){
                qu.push(pair<int, int>(temp.first + 1, temp.second));
                if(grid[temp.first + 1][temp.second] != 1)
                    grid[temp.first + 1][temp.second] = grid[temp.first][temp.second] + 1;
            }
            if(temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == 0){
                qu.push(pair<int, int>(temp.first - 1, temp.second));
                if(grid[temp.first - 1][temp.second] != 1)
                    grid[temp.first - 1][temp.second] = grid[temp.first][temp.second] + 1;
            }
            if(temp.second + 1 < max_y && grid[temp.first][temp.second + 1] == 0){
                qu.push(pair<int, int>(temp.first, temp.second + 1));
                if(grid[temp.first][temp.second + 1] != 1)
                   grid[temp.first][temp.second + 1] = grid[temp.first][temp.second] + 1;
            }
            if(temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == 0){
                qu.push(pair<int, int>(temp.first, temp.second - 1));
                if(grid[temp.first][temp.second - 1] != 1)
                    grid[temp.first][temp.second - 1] = grid[temp.first][temp.second] + 1;
            }
            n++;
        }
        return n - 1;
    }         
};

int main(){
    vector<vector<int>> grid = {{0,0,0}, {0,0,0}, {0,0,0}};
    Solution a;
    a.maxDistance(grid);
}

