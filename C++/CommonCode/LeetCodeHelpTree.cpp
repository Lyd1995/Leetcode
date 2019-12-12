#include "LeetCodeHelpTree.h"


// 利用LeetCode的中序遍历，生成一颗二叉树
TreeNode* LeetCodeHelpTree::buildBinaryTreeUseInOrderTraversal(vector<string>& tree) {
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(0);
	if (tree.empty() || tree[0] == "null")
		return NULL;
	else
		root->val = stoi(tree[0]);
	q.push(root);
	int k = 1;
	while (!q.empty()) {
		int q_len = q.size();
		for (int i = 0; i < q_len; i++) {
			TreeNode* temp = q.front();
			q.pop();
			// 设置左子树
			if (k < tree.size() && tree[k] != "null") {
				temp->left = new TreeNode(stoi(tree[k]));
			}
			k++;
			// 设置右子树
			if (k < tree.size() && tree[k] != "null") {
				temp->right = new TreeNode(stoi(tree[k]));
			}
			k++;
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return root;
}

//        这个函数可以将字符串，转换为字符串数组，要求输入的字符串（符合LeetCode的binary tree标准）：
//                    "[10,5,-3,3,2,null,11,3,-2,null,1]"
vector<string> LeetCodeHelpTree::string2vector(string s) {
	int begin = s.find('[');
	int end = s.find(']');
	string str = s.substr(begin + 1, end - begin - 1);
	vector<string> ans = splitString(str, ',');
	return ans;
}

// 直接输入字符串，也能转换为二叉树
TreeNode* LeetCodeHelpTree::buildBinaryTreeUseInOrderTraversal(string stringTree) {
	vector<string> tree = string2vector(stringTree);
	return buildBinaryTreeUseInOrderTraversal(tree);
}

// 以某个字符ch为分隔符，将字符串分割成多个字符串，返回一个字符串数组
vector<string> LeetCodeHelpTree::splitString(string s, char ch) {
	vector<string> ans;
	int k;
	s += ch;    // 以 ch 分割符作为结尾
	for (int i = 0; i < s.size(); i++) {
		while (s[i] == ' ')
			i++;
		k = i;
		while (s[i] != ch)
			i++;
		string temp = s.substr(k, i - k);   // 此时：s[i] == ch
		ans.push_back(temp);
	}
	return ans;
}
