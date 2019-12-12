#ifndef LEETCODEHELPTREE_H
#define LEETCODEHELPTREE_H


#include "LeetCode.h"


class LeetCodeHelpTree {
public:
	// ����LeetCode���������������һ�Ŷ�����
	TreeNode* buildBinaryTreeUseInOrderTraversal(vector<string>& tree);

	// ����LeetCode���������������һ�Ŷ�����
	TreeNode* buildBinaryTreeUseInOrderTraversal(string stringTree);

	//    ����������Խ��ַ�����ת��Ϊ�ַ������飬Ҫ��������ַ���������LeetCode��binary tree��׼����
	//        "[10,5,-3,3,2,null,11,3,-2,null,1]"
	vector<string> string2vector(string s);

	// ��ĳ���ַ�chΪ�ָ��������ַ����ָ�ɶ���ַ���������һ���ַ�������
	vector<string> splitString(string s, char ch);
};
#endif // !LEETCODEHELPTREE_H
