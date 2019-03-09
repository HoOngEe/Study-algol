#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	int tc_count;
	scanf("%d", &tc_count);

	for (int i = 0; i < tc_count; i++) {
		int number;
		scanf("%d", &number);
		for (int j = 0; number > 0; j++, number >>= 1) {
			if (number & 1)
				printf("%d ", j);
		}
		printf("\n");
	}
}