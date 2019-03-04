#include<cstdio>

using namespace std;

int main() {
	int tc_count;
	char ox;
	int stack, score;
	scanf("%d%*c", &tc_count);

	for (int i = 0; i < tc_count; i++) {
		score = 0;
		stack = 0;
		while (true) {
			scanf("%c", &ox);
			if (ox == '\n')
				break;
			else if (ox == 'O')
				stack++;
			else
				stack = 0;
			score += stack;
		}
		printf("%d\n", score);
	}

	return 0;
}