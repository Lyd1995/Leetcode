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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> ans;
        if(root == NULL)
            return ans;
        findPath(root, s, ans);
        return ans;
    }

    void findPath(TreeNode* root, string& s, vector<string>& path){
        s = s + "->" + int2string(root->val);
        if(root->right == NULL && root->left == NULL) // 叶子节点
            path.push_back(s.substr(2));
        else{
            if(root->left){
                findPath(root->left, s, path);
                int i = s.size() - 1;
                while(s[i] != '>')
                    i--;
                s.erase(i - 1);
            }
            if(root->right){
                findPath(root->right, s, path);
                int i = s.size() - 1;
                while(s[i] != '>')
                    i--;
                s.erase(i - 1);
            }
        }
        return;
    }

    string int2string(int num){
        if(num == 0)
            return "0";
        bool flag_neg = false;
        if(num < 0){
            flag_neg = true;
            num = -num;
        }
        string ans;
        while(num){
            int temp = num % 10;
            char ch = temp + '0';
            ans = ch + ans;
            num /= 10;
        }
        if(flag_neg)
            ans = "-" + ans;
        return ans;
    }
};