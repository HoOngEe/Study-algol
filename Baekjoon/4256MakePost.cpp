#include<iostream>
using namespace std;

void arrange(int*, int*, int, int*, int*);
void post_order(int, int*, int *);

int main() {
	int tc_cnt, node_cnt;
	int preorder[1000] = { 0 };
	int inorder[1000] = { 0 };
	cin >> tc_cnt;

	for (int i = 0; i < tc_cnt; i++) {
		int tree_left[1000] = { 0 };
		int tree_right[1000] = { 0 };
		cin >> node_cnt;
		for (int j = 0; j < node_cnt; j++) {
			cin >> preorder[j];
		}
		for (int j = 0; j < node_cnt; j++) {
			cin >> inorder[j];
		}
		arrange(preorder, inorder, node_cnt, tree_left, tree_right);
		int root = preorder[0];
		post_order(root, tree_left, tree_right);
		cout << endl;
	}
}

void post_order(int parent, int* tree_left, int* tree_right) {
	if (parent == 0)
		return;
	post_order(tree_left[parent], tree_left, tree_right);
	post_order(tree_right[parent], tree_left, tree_right);
	cout << parent << " ";
}

void arrange(int* pre, int* in, int len, int* tree_left, int* tree_right) {
	if (len <= 1)
		return;
	int parent = pre[0];
	int parent_idx = 0;
	for (int i = 0; i < len; i++) {
		if (in[i] == parent)
			parent_idx = i;
	}
	int new_left_len = parent_idx;
	if (parent_idx != 0)
		tree_left[parent] = pre[1];
	if (parent_idx != len - 1)
		tree_right[parent] = pre[new_left_len + 1];

	arrange(pre + 1, in, new_left_len, tree_left, tree_right);
	arrange(pre + new_left_len + 1, in + new_left_len + 1, len - new_left_len - 1, tree_left, tree_right);
}