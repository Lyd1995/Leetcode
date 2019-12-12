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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int count, layer = 0;
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        else
            return 0;
        bool flag = true;
        while(!q.empty()){
            layer++;
            int len = q.size();
            count = len;
            if(count & (count - 1) != 0){
                flag = false;
                break;
            }
            for(int i=0; i < len; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        
        if(flag){
            return pow(2, layer - 1);
        }
        else{
            count += pow(2, layer - 2);
            return count;
        }
    }
};