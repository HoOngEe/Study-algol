#include<iostream>
#include<map>

using namespace std;

class Children{
public:
	char left;
	char right;
	Children(char, char);
	Children();
};

Children::Children(char l, char r) {
	left = l;
	right = r;
}

Children::Children() {
	left = '.';
	right = '.';
}

void pre_order(map<char, Children>, char);
void post_order(map<char, Children>, char);
void in_order(map<char, Children>, char);

int main() {
	char parent, left, right;
	char root;
	map<char, Children> tree;
	int node_cnt;
	cin >> node_cnt;

	cin >> root >> left >> right;
	tree[root] = Children(left, right);
	for (int i = 1; i < node_cnt; i++) {
		cin >> parent >> left >> right;
		tree[parent] = Children(left, right);
	}

	pre_order(tree, root);
	cout << endl;
	in_order(tree, root);
	cout << endl;
	post_order(tree, root);
	cout << endl;
}

void pre_order(map<char, Children> tree, char parent) {
	if (parent == '.')
		return;
	cout << parent;
	pre_order(tree, tree[parent].left);
	pre_order(tree, tree[parent].right);
}

void in_order(map<char, Children> tree, char parent) {
	if (parent == '.')
		return;
	in_order(tree, tree[parent].left);
	cout << parent;
	in_order(tree, tree[parent].right);
}

void post_order(map<char, Children> tree, char parent) {
	if (parent == '.')
		return;
	post_order(tree, tree[parent].left);
	post_order(tree, tree[parent].right);
	cout << parent;
}