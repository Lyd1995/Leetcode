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

class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        init(root);
        _root = root;
    }

    void init(TreeNode* root) {
        if(root->left) {
            root->left->val = root->val * 2 + 1;
            init(root->left);
        }
        if(root->right) {
            root->right->val = root->val * 2 + 2;
            init(root->right);
        }
    }
    
    bool find(int target) {
        return findT(target, _root);
    }

    bool findT(int target, TreeNode* root){
        if(target == root->val)
            return true;
        if(target < root->val)
            return false;
        bool ans = false;
        if(root->left)
            ans = ans || findT(target, root->left);
        if(root->right)
            ans = ans || findT(target, root->right);
        return ans;
    }

private:
    TreeNode* _root;
};