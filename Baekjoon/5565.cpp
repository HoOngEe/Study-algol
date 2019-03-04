#include<cstdio>

using namespace std;

int main() {
	int sum, price;
	scanf("%d", &sum);

	for (int i = 0; i < 9; i++) {
		scanf("%d", &price);
		sum -= price;
	}

	printf("%d", sum);
	return 0;
}

