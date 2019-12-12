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
        int i = 1;
        for(; i < path_p.size() && i < path_q.size(); i++){
            if(path_p[i] != path_q[i])
                break;
        }
        return path_p[i - 1];
    }

    void findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
        path.push_back(root);
        if(root->val == p->val)
            return;
        else if(root->val < p->val)
            findPath(root->right, p, path);
        else
            findPath(root->left, p, path);
    }
};

class Solution {
public:
    // 找第一个介于两者之间的节点
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isIn(root->val, p->val, q->val))
            return root;
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }

    bool isIn(int a, int x1, int x2){
        if(a >= x1 && a <= x2)
            return true;
        if(a >= x2 && a <= x1)
            return true;
        return false;
    }
};