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

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int max_i = matrix.size() - 1, max_j = matrix[0].size() - 1, i = 0, j = 0, offset = 0;
        vector<int> nums(4);
        // 一圈一圈地比较
        while(i <= max_i && j <= max_j){
            nums[0] = matrix[i][j];
            nums[1] = matrix[i][max_j];
            nums[2] = matrix[max_i][j];
            nums[3] = matrix[max_i][max_j];
            if(target < nums[0])
                return false;
            if(target > nums[3])
                return false;
            if(target == nums[0] || target == nums[1] || target == nums[2] || target == nums[3])
                return true;
            if(target < nums[1]){   //  在第i行查找
                if(searchRow(matrix, target, i))
                    return true;
            }
            else{                   // 在第max_j列查找
                if(searchCol(matrix, target, max_j))
                    return true;
            }
            
            
            if(target < nums[2]){   //  在第j列查找
                if(searchCol(matrix, target, j))
                    return true;
            }
            else{                   // 在第max_i列查找
                if(searchRow(matrix, target, max_i))
                    return true;
            }

            i++;
            j++;
            max_i--;
            max_j--;
        }
        return false;
    }

    bool searchRow(vector<vector<int>>& matrix, int& target, int row){
        int i = 0, j = matrix[0].size() - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(target == matrix[row][mid])
                return true;
            if(target > matrix[row][mid])
                i = mid + 1;
            else
                j = mid;
        }
        return false;
    }

    bool searchCol(vector<vector<int>>& matrix, int& target, int col){
        int i = 0, j = matrix.size() - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(target == matrix[mid][col])
                return true;
            if(target > matrix[mid][col])
                i = mid + 1;
            else
                j = mid;
        }
        return false;
    }
};

int main(){
    //vector<vector<int>> v = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    vector<vector<int>> v = {{1,3,5,7,9},{2,4,6,8,10},{11,13,15,17,19},{12,14,16,18,20},{21,22,23,24,25}};
    //vector<vector<int>> v = {{1,4,7,11,15}};
    Solution a;
    bool ans = a.searchMatrix(v, 13);
    return 0;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int max_i = matrix.size(), max_j = matrix[0].size(), i = 0, j = max_j - 1;
        while(i < max_i && j >= 0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};