#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	int tc_count;
	scanf("%d%*c", &tc_count);
	for (int i = 0; i < tc_count; i++) {
		char arr[26] = { 0 };
		int total_sum = 0;
		char c;
		while (true) {
			scanf("%c", &c);
			if (c == '\n')
				break;
			else
				arr[c - 'A'] = 1;
		}
		for (int j = 0; j < 26; j++) {
			if (!arr[j])
				total_sum += j + 'A';
		}
		printf("%d\n", total_sum);
	}
}