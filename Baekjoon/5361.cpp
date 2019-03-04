#include<cstdio>

using namespace std;

int main() {
	int tc_count;
	int a, b, c, d, e;
	double ap = 350.34;
	double bp = 230.90;
	double cp = 190.55;
	double dp = 125.30;
	double ep = 180.90;
	scanf("%d", &tc_count);

	for (int i = 0; i < tc_count; i++) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		printf("\$%.2lf\n", a * ap + b * bp + c * cp + d * dp + e * ep);
	}

	return 0;
}

