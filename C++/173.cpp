#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    queue<int> min_q;
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    void inOrder(TreeNode* root){
        if(root == NULL)
            return;
        if(root->left)
            inOrder(root->left);
        min_q.push(root->val);
        if(root->right)
            inOrder(root->right);
    }
    /** @return the next smallest number */
    int next() {
        int ans = min_q.front();
        min_q.pop();
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(min_q.empty())
            return false;
        else
            return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */