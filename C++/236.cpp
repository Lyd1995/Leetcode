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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        // reverse(path_p.begin(), path_p.end());
        // reverse(path_q.begin(), path_q.end());
        int i = path_p.size(), j = path_q.size();
        while(--i >= 0 && --j >=0){
            if(path_p[i] != path_q[j])
                break;
        }
        return path_p[i + 1];
    }

    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
        if(root == NULL)
            return false;
        if(root->val == p->val){
            path.push_back(root);
            return true;
        }
        if(findPath(root->left, p, path) || findPath(root->right, p, path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
};