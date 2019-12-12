#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

// 二叉搜索区间树
struct TreeNode2 {
    int val, leftval, rightval;
    int pos;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2(int x, int i, int t) : val(x), leftval(x - t), rightval(x + t), pos(i), left(NULL), right(NULL) {};
};

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2)
            return false;
        TreeNode2* root = new TreeNode2(nums[0], 0, t);
        for(int i=1; i < nums.size(); i++)
            generateTree(root, nums[i], i, t);
        for(int i=0; i < nums.size(); i++){
            if(searchTree(root, nums[i], i, k, t))
                return true;
        }
        return false;
    }

    void generateTree(TreeNode2* root, int& val, int& pos, int& t){
        if(val > root->val){
            if(root->right)
                generateTree(root->right, val, pos, t);
            else{
                TreeNode2* temp = new TreeNode2(val, pos, t);
                root->right = temp;
            }
        }
        else{
            if(root->left)
                generateTree(root->left, val, pos, t);
            else{
                TreeNode2* temp = new TreeNode2(val, pos, t);
                root->left = temp;
            }
        }
    }

    bool searchTree(TreeNode2* root, int& val, int& pos, int& k, int& t){
        if(root->pos != pos){
            
        }
        else{
            bool flag_left = false, flag_right = false;
            // 往左子树搜索
            if(root->left)
                flag_left = searchTree(root->left, val, pos, k, t);
            if(flag_left)
                return true;
            // 往右子树搜索
            if(root->right)
                flag_right = searchTree(root->right, val, pos, k, t);
            if(flag_right)
                return true;
            return false;
        }
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <= 0)
            return false;
        set<long> list;
        for(int i=0; i < nums.size(); i++){
            auto num = list.lower_bound(long(nums[i]) - long(t));
            if(num != list.end() && *num <= long(nums[i]) + long(t))
                return true;
            list.insert(nums[i]);
            if(list.size() > k)
                list.erase(nums[i - k]);
        }
        return false;
    }
};

int main(){
    Solution a;
    vector<int> nums = {1,2,3,1};
    a.containsNearbyAlmostDuplicate(nums, 3, 0);
}