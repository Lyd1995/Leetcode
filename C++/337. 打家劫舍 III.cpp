#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int rob(TreeNode* root) {
        int ans = 0;
        vector<int> dp = dfs(root);
        ans = max(dp[0], dp[1]);
        return ans;
    }

    vector<int> dfs(TreeNode* root){
        vector<int> dp(2, 0);
        if(root == NULL)
            return dp;
        vector<int> left(2, 0), right(2, 0);
        if(root->left)
            left = dfs(root->left);
        if(root->right)
            right = dfs(root->right);
        int temp1 = max(left[0] + right[0], left[1] + right[0]), temp2 = max(left[1] + right[1], left[0] + right[1]);
        dp[0] = max(temp1, temp2);
        dp[1] = left[0] + right[0] + root->val;
        return dp;
    }
};