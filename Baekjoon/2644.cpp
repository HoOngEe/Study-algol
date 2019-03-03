#include<iostream>
#include<deque>
using namespace std;

int main() {
	int people_cnt, relation_cnt;
	int target1, target2;
	deque<int> parent_trace1;
	deque<int> parent_trace2;
	int parent_indicator[100] = { 0 };
	int temp;

	cin >> people_cnt;
	cin >> target1 >> target2;
	cin >> relation_cnt;

	for (int i = 0; i < relation_cnt; i++) {
		int parent, child;
		cin >> parent >> child;
		parent_indicator[child] = parent;
	}

	temp = target1;
	parent_trace1.push_back(temp);
	while (temp = parent_indicator[temp])
		parent_trace1.push_front(temp);

	temp = target2;
	parent_trace2.push_back(temp);
	while (temp = parent_indicator[temp])
		parent_trace2.push_front(temp);

	int navigate_idx = 0;
	while (true) {
		if (parent_trace1[navigate_idx] != parent_trace2[navigate_idx])
			break;
		navigate_idx++;
	}

	int chonsu; 
	if (navigate_idx == 0)
		chonsu = -1;
	else
		chonsu = parent_trace1.size() - navigate_idx + parent_trace2.size() - navigate_idx;

	cout << chonsu;
}