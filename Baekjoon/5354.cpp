#include<cstdio>

using namespace std;

int main() {
	int tc_count, size;
	scanf("%d", &tc_count);

	for (int i = 0; i < tc_count; i++) {
		char box[10][10] = { { 0 } };
		scanf("%d", &size);
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				box[j][k] = '#';
			}
		}
		for (int j = 1; j < size - 1; j++) {
			for (int k = 1; k < size - 1; k++) {
				box[j][k] = 'J';
			}
		}
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				printf("%c", box[j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

