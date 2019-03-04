#include<cstdio>

using namespace std;

int main() {
	int score, avg = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &score);
		if (score < 40)
			avg += 8;
		else
			avg += score / 5;
	}

	printf("%d\n", avg);
	return 0;
}