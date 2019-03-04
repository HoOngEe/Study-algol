#include<vector>
#include<cstdio>
#include<utility>

using namespace std;

void in_order_store(vector<int> &xpos, vector<pair<int, int>>&child_relation, int parent) {
	if (parent == -1)
		return;
	in_order_store(xpos, child_relation, child_relation[parent].first);
	xpos.push_back(parent);
	in_order_store(xpos, child_relation, child_relation[parent].second);
}

int find_root(vector<int>& parent_relation) {
	int i = 1;
	while (parent_relation[i] != -1) {
		i = parent_relation[i];
	}
	return i;
}

void depth_store(vector<vector<int>>& from_depth, vector<pair<int, int>>& child_relation, int parent, int depth) {
	if (parent == -1)
		return;
	from_depth[depth].push_back(parent);
	depth_store(from_depth, child_relation, child_relation[parent].first, depth + 1);
	depth_store(from_depth, child_relation, child_relation[parent].second, depth + 1);
}

int main() {
	int node_cnt;
	int dummy = 0;
	
	scanf("%d", &node_cnt);
	vector<pair<int, int>> child_relation(node_cnt + 1);
	vector<int> parent_relation(node_cnt + 1, -1);
	vector<int> xpos;
	vector<vector<int>> from_depth(node_cnt + 1);
	xpos.reserve(node_cnt);

	vector<int> xpos_reverse_map(node_cnt + 1);

	for (int i = 1; i < node_cnt + 1; i++) {
		int parent, left, right;
		scanf("%d %d %d", &parent, &left, &right);
		child_relation[parent] = make_pair(left, right);
		if(left != -1)
			parent_relation[left] = parent;
		if(right != -1)
			parent_relation[right] = parent;
	}
	int root = find_root(parent_relation);
	in_order_store(xpos, child_relation, root);
	depth_store(from_depth, child_relation, root, 0);

	for (int i = 0; i < node_cnt; i++) {
		xpos_reverse_map[xpos[i]] = i + 1;
	}

	int max_idx = 1;
	int max_val = 0;
	int i = 0;
	while(from_depth[i].size() > 0) {
		int width = xpos_reverse_map[from_depth[i].back()] - xpos_reverse_map[from_depth[i].front()] + 1;
		if (width > max_val) {
			max_idx = i + 1;
			max_val = width;
		}
		i++;
	}

	printf("%d %d\n", max_idx, max_val);
	return 0;
}

