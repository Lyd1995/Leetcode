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
#include<stdlib.h>
using namespace std;

class Solution {
public:
    // 完成一次先序遍历，若是能够将字符串遍历完成，则说明正确
    bool isValidSerialization(string preorder) {
        if(preorder[0] == '#')
            return (preorder.size() == 1);
        vector<string> pre;
        for(int i=0; i < preorder.size(); i++){
            int j = i;
            while(i < preorder[i] != ',')
                i++;
            pre.push_back(preorder.substr(j, i - j));
        }
        if(pre.size() < 3)
            return false;
        int next = solve(pre, 0);
        return (next == pre.size());
    }


    int solve(vector<string>& preorder, int root){
        if(root < preorder.size()){
            if(preorder[root] == "#")
                return root + 1;
            if(root + 2 < preorder.size()){     // 判断root树是否合法
                if(preorder[root + 1] != "#") {  // 左子树不空
                    int left_end = solve(preorder, root + 1);
                    if(left_end == -1)
                        return -1;
                    return solve(preorder, left_end);
                }
                else if(preorder[root + 2] != "#"){
                    return solve(preorder, root + 2);
                }
                else{
                    return root + 3;
                }
            }
            return -1;
        }
        return root;
    }
};


int main(){
    string s = "9,9,9,9,9,#,#,#,9,#,9,9,#,#,#,9,9,9,9,9,#,#,9,#,9,9,#,#,#,9,9,#,#,#,9,#,#,9,9,9,#,#,#,9,#,#,9,9,9,#,#,#,9,9,9,9,#,9,#,9,#,#,9,#,#,9,#,#,9,#,#";
    Solution a;
    auto b = a.isValidSerialization(s);
    return 0;
}