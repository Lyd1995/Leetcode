#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> qu;
        if(root)
            qu.push(root);
        while(!qu.empty()){
            int len = qu.size(), i;
            for(i = 0; i < len; i++){
                TreeNode* temp = qu.front();
                qu.pop();
                if(temp->left)
                    qu.push(temp->left);
                if(temp->right)
                    qu.push(temp->right);
                if(i == len - 1)
                    ans.push_back(temp->val);
            }
        }
        return ans;
    }
};