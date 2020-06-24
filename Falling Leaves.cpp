#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
//#define INT_MAX 2147483647

using namespace std;

const int maxn = 30;

typedef struct TNode* node;
struct TNode {
	char val;
	node left;
	node right;
};
node root;

void insert(node r, char c) {
	if (root == NULL) {
		root = new TNode;
		root->val = c;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		if (c > r->val) {
			if (r->right == NULL) {
				node rchild = new TNode;
				rchild->val = c;
				rchild->left = NULL;
				rchild->right = NULL;
				r->right = rchild;
			}
			else {
				insert(r->right, c);
			}
		}
		else if (c < r->val) {
			if (r->left == NULL) {
				node lchild = new TNode;
				lchild->val = c;
				lchild->left = NULL;
				lchild->right = NULL;
				r->left = lchild;
			}
			else {
				insert(r->left, c);
			}
		}
	}
}

void preorder(node r) {
	if (r == NULL)
		return;
	cout << r->val;
	preorder(r->left);
	preorder(r->right);
}

int main() {
	char map[maxn][maxn];
	int flag = 1;
	while (flag) {
		int count = 0;
		while (true) {
			cin >> map[count];
			if (map[count][0] == '$') {
				flag = 0;
				break;
			}
			if (map[count][0] == '*') break;
			count++;
		}
		int i, j;
		root = NULL;
		for (int i = count - 1; i >= 0; i--) {
			for (j = 0; j < strlen(map[i]); j++)
				insert(root, map[i][j]);
		}
		preorder(root);
		cout << endl;
	}
	return 0;
}
