#include<cstdio>

using namespace std;

void mat_mul(int mat_a[][100], int mat_b[][100], int n, int m, int k, int result[][100]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int sum = 0;
			for (int z = 0; z < m; z++) {
				sum += mat_a[i][z] * mat_b[z][j];
			}
			result[i][j] = sum;
		}
	}
}

int main() {
	int n, m, k;
	int mat_a[100][100];
	int mat_b[100][100];
	int result[100][100];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat_a[i][j]);
		}
	}

	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &mat_b[i][j]);
		}
	}

	mat_mul(mat_a, mat_b, n, m, k, result);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}