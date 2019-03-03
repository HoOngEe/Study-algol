#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstdio>

using namespace std;

pair<int, int> operate(pair<int, int> a, pair<int, int> b) {
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}

pair<int, int> init(vector<int>& integers, vector<pair<int, int>>& seg_tree, int node, int start, int end) {
	if (start == end)
		return seg_tree[node] = make_pair(integers[start], integers[start]);
	else
		return seg_tree[node] = operate(init(integers, seg_tree, node * 2, start, (start + end) / 2),
			init(integers, seg_tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

pair<int,int> calculate(vector<pair<int, int>>& seg_tree, int node, int start, int end, int target_left, int target_right) {
	if (target_left > end || target_right < start)
		return make_pair(1000000001, 0);
	else if (target_left <= start && target_right >= end) {
		return seg_tree[node];
	}
	return operate(
		calculate(seg_tree, 2 * node, start, (start + end) / 2, target_left, target_right),
		calculate(seg_tree, 2 * node + 1, (start + end) / 2 + 1, end, target_left, target_right));
}

int main() {
	int integer_cnt, pair_cnt;
	
	scanf("%d %d", &integer_cnt, &pair_cnt);
	vector<int> integers;
	integers.reserve(integer_cnt);

	for (int i = 0; i < integer_cnt; i++) {
		int temp;
		scanf("%d", &temp);
		integers.push_back(temp);
	}

	int tree_height = (int)ceil(log2(integer_cnt));
	int tree_size = (1 << (tree_height + 1));
	vector<pair<int, int>> seg_tree(tree_size);

	init(integers, seg_tree, 1, 0, integer_cnt - 1);

	for (int i = 0; i < pair_cnt; i++) {
		int left, right;
		scanf("%d %d", &left, &right);
		pair<int, int>result = calculate(seg_tree, 1, 0, integer_cnt - 1, left - 1, right - 1);
		printf("%d %d\n", result.first, result.second);
	}
}