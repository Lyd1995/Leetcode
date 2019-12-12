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
    void gameOfLife(vector<vector<int>>& board) {
        solve(board);
        return;
    }

    void solve(vector<vector<int>>& board){
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(board[i][j]){
                    if(isLive(board, i, j, true) == false)
                        board[i][j] = 3;
                }
                else{
                    if(isLive(board, i, j, false) == true)
                        board[i][j] = 2;
                }
            }
        }
        // 更新面板
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(board[i][j] == 3)
                    board[i][j] = 0;
                if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
        return;
    }

    bool isLive(vector<vector<int>>& board, int x, int y, bool flag){
        int count = 0;
        int max_x = board.size(), max_y = board[0].size();
        int left = max(x - 1, 0), right = min(x + 2, max_x);
        int bottom = max(y - 1, 0), top = min(y + 2, max_y);
        // 统计该细胞周围活细胞的个数
        for(int i=left; i < right; i++){
            for(int j=bottom; j < top; j++){
                if(board[i][j] % 2 == 1)
                    count++;
            }
        }
        // 判断该细胞的死活
        if(flag){   // 表示当前细胞为活细胞
            count--;
            if(count == 2 || count == 3)
                return true;
            return false;
        }
        else{       // 表示当前细胞为死细胞
            if(count == 3)
                return true;
            return false;
        }
    }
};

int main(){
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution a;
    a.gameOfLife(board);

    return 0;
}