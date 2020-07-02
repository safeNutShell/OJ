#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

typedef struct TNode* node;
struct TNode {
	char val;
	node left, right;
	TNode(char a) {
		this->val = a;
		this->left = NULL;
		this->right = NULL;
	}
};

node buildTree(string& preorder, string& inorder, int preleft, int preright, int inleft, int inright) {
	if (preleft > preright || inleft > inright) return NULL;
	node cur = new TNode(preorder[preleft]);
	int ptr = inleft;
	while (ptr<=inright && inorder[ptr] != preorder[preleft]) ptr++;
	int len = ptr - inleft;
	cur->left = buildTree(preorder, inorder, preleft + 1, preleft + len, inleft, ptr - 1);
	cur->right = buildTree(preorder, inorder, preleft + len + 1, preright, ptr + 1, inright);
	return cur;
}

void postTravel(node T) {
	if (T->left != NULL)
		postTravel(T->left);
	if (T->right != NULL)
		postTravel(T->right);
	cout << T->val;
}

int main() {
	string pre, in;
	while (cin >> pre >> in) {
		node root = new TNode(0);
		root = buildTree(pre, in, 0, pre.length() - 1, 0, in.length() - 1);
		postTravel(root);
		cout << endl;
		delete root;
	}
	return 0;
}
