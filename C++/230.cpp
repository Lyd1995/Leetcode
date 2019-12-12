#include<iostream>
#include<vector>
#include<string>
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
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历
        stack<TreeNode*> st1;
        set<TreeNode*> list;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* temp = st1.top();
            st1.pop();
            // 处理temp元素
            if(list.count(temp)){
                k--;
                if(k == 0)
                    return temp->val;
            }
            else{
                if(temp->right)
                    st1.push(temp->right);
                
                list.insert(temp);
                st1.push(temp);
                
                if(temp->left)
                    st1.push(temp->left);
            }
        }
        return 0;
    }
};

int main(){

}