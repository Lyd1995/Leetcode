#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;


class Solution1 {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<pair<int, int>> mat(4);
        pair<int, int> mat1_left_bot(A, B), mat1_right_top(C, D), mat2_left_bot(E, F), mat2_right_top(G, H);
        mat.push_back(mat1_left_bot);
        mat.push_back(mat1_right_top);
        mat.push_back(mat2_left_bot);
        mat.push_back(mat2_right_top);
        // 1、相交的情况
        if(isIntersect(mat)){
            // 1.1 包含     2种情况
            int area = 0;
            if(isInclude(mat, area)){
                return area;
            }
            else{   // 1.2 相交 4种情况

            }
        }
        else    // 2、不相交的情况  4种情况
            return 0;
    }

    bool isIntersect(vector<pair<int, int>>& mat){

    }

    bool isInclude(vector<pair<int, int>>& mat, int& area){
        if(mat[3].first > mat[1].first && mat[3].second > mat[1].second && mat[2].second < mat[0].second && mat[2].first < mat[0].first){
            area = (mat[1].first - mat[0].first) * (mat[1].second - mat[0].second);
            return true;
        }

        if(mat[3].first < mat[1].first && mat[3].second < mat[1].second && mat[2].second > mat[0].second && mat[2].first > mat[0].first){
            area = (mat[3].first - mat[2].first) * (mat[3].second - mat[2].second);
            return true;
        }

        return false;
    }

    void computeIntersect(vector<pair<int, int>>& mat, int& area){
        
    }

    // 判断点A是否在点B的右边
    bool isRight(pair<int, int>& A, pair<int, int>& B){
        if(A.first > B.first)
            return true;
        return false;
    }

    // 判断点A是否在点B的左边
    bool isLeft(pair<int, int>& A, pair<int, int>& B){
        if(A.first < B.first)
            return true;
        return false;
    }

    // 判断点A是否在点B的上面
    bool isUp(pair<int, int>& A, pair<int, int>& B){
        if(A.second > B.second)
            return true;
        return false;
    }

    // 判断点A是否在点B的下面
    bool isDown(pair<int, int>& A, pair<int, int>& B){
        if(A.second < B.second)
            return true;
        return false;
    }

};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long max_x1 = C, max_x2 = G, max_y1 = D, max_y2 = H;
        long min_x1 = A, min_x2 = E, min_y1 = B, min_y2 = F;
        long x1_len = max_x1 - min_x1, x2_len = max_x2 - min_x2;
        long y1_len = max_y1 - min_y1, y2_len = max_y2 - min_y2;

        long x_len = min(min(max_x1 - min_x2, max_x2 - min_x1), min(x1_len, x2_len));
        long y_len = min(min(max_y1 - min_y2, max_y2 - min_y1), min(y1_len, y2_len));
        long intersect_area = x_len * y_len;
        long area1 = x1_len * y1_len, area2 = x2_len * y2_len;

        if(max_x1 < max_x2 && max_y1 < max_y2 && min_x1 > min_x2 && min_y1 > min_y2)
            return area2;
        else if(max_x2 < max_x1 && max_y2 < max_y1 && min_x2 > min_x1 && min_y2 > min_y1)
            return area1;
        else if(x_len < 0 || y_len < 0 || area1 == 0 || area2 == 0)
            intersect_area =  0;
        return  area1 + area2 - intersect_area;
    }
    
};