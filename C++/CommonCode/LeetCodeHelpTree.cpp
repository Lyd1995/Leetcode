#include "LeetCodeHelpTree.h"


// ����LeetCode���������������һ�Ŷ�����
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
			// ����������
			if (k < tree.size() && tree[k] != "null") {
				temp->left = new TreeNode(stoi(tree[k]));
			}
			k++;
			// ����������
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

//        ����������Խ��ַ�����ת��Ϊ�ַ������飬Ҫ��������ַ���������LeetCode��binary tree��׼����
//                    "[10,5,-3,3,2,null,11,3,-2,null,1]"
vector<string> LeetCodeHelpTree::string2vector(string s) {
	int begin = s.find('[');
	int end = s.find(']');
	string str = s.substr(begin + 1, end - begin - 1);
	vector<string> ans = splitString(str, ',');
	return ans;
}

// ֱ�������ַ�����Ҳ��ת��Ϊ������
TreeNode* LeetCodeHelpTree::buildBinaryTreeUseInOrderTraversal(string stringTree) {
	vector<string> tree = string2vector(stringTree);
	return buildBinaryTreeUseInOrderTraversal(tree);
}

// ��ĳ���ַ�chΪ�ָ��������ַ����ָ�ɶ���ַ���������һ���ַ�������
vector<string> LeetCodeHelpTree::splitString(string s, char ch) {
	vector<string> ans;
	int k;
	s += ch;    // �� ch �ָ����Ϊ��β
	for (int i = 0; i < s.size(); i++) {
		while (s[i] == ' ')
			i++;
		k = i;
		while (s[i] != ch)
			i++;
		string temp = s.substr(k, i - k);   // ��ʱ��s[i] == ch
		ans.push_back(temp);
	}
	return ans;
}
