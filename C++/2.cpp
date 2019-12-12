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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> qu1, qu2;
        long long maxval=INT32_MIN, count;
        int layers_max, num=0;
        qu1.push(root);
        while(!qu1.empty() || !qu2.empty()){
            num++;
            count=0;
            while(!qu1.empty()){
                TreeNode* temp = qu1.front();
                qu1.pop();
                count += temp->val;
                if(temp->left)
                    qu2.push(temp->left);
                if(temp->right)
                    qu2.push(temp->right);
            }
            if(count > maxval){
                maxval = count;
                layers_max = num;
            }

            // next layer
            num++;
            count = 0;
            while(!qu2.empty()){
                TreeNode* temp = qu2.front();
                qu2.pop();
                count += temp->val;
                if(temp->left)
                    qu1.push(temp->left);
                if(temp->right)
                    qu1.push(temp->right);
            }
            if(count > maxval){
                maxval = count;
                layers_max = num;
            }
        }
        return layers_max;
    }
};