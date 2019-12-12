#ifndef LEETCODEHELPTREE_H
#define LEETCODEHELPTREE_H


#include "LeetCode.h"


class LeetCodeHelpTree {
public:
	// 利用LeetCode的中序遍历，生成一颗二叉树
	TreeNode* buildBinaryTreeUseInOrderTraversal(vector<string>& tree);

	// 利用LeetCode的中序遍历，生成一颗二叉树
	TreeNode* buildBinaryTreeUseInOrderTraversal(string stringTree);

	//    这个函数可以将字符串，转换为字符串数组，要求输入的字符串（符合LeetCode的binary tree标准）：
	//        "[10,5,-3,3,2,null,11,3,-2,null,1]"
	vector<string> string2vector(string s);

	// 以某个字符ch为分隔符，将字符串分割成多个字符串，返回一个字符串数组
	vector<string> splitString(string s, char ch);
};
#endif // !LEETCODEHELPTREE_H
