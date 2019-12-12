// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "LeetCode.h"
#include "LeetCodeHelpTree.h"


class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		vector<int> nums = { 0 };
		return pathSum(root, 0, sum, nums);
	}

	// 在某一顶点，计算是否与target相等时，必须将该顶点的value计入
	int pathSum(TreeNode* root, int preSum, int& target, vector<int>& nums) {
		int ans = 0;
		if (root) {
			// 计算以该顶点为起点，往上，符合条件的路径
			int sum = root->val + preSum;
			for (int i = 0; i < nums.size(); i++) {
				sum -= nums[i];
				if (sum == target)
					ans++;
			}
			nums.push_back(root->val);

			// 遍历左右子树
			if (root->left) {
				ans += pathSum(root->left, root->val + preSum, target, nums);
				nums.pop_back();
			}
			if (root->right) {
				ans += pathSum(root->right, root->val + preSum, target, nums);
				nums.pop_back();
			}
		}
		return ans;
	}
};


int main()
{
    std::cout << "Hello World!\n";
	string s = "[10,5,-3,3,2,null,11,3,-2,null,1]";
	LeetCodeHelpTree help1;
	TreeNode* root = help1.buildBinaryTreeUseInOrderTraversal(s);
	Solution a;
	a.pathSum(root, 8);

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
