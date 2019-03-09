#include<cstdio>
#include<cmath>

using namespace std;

int get_clock(int a[]) {
	int min = 10000;
	for (int i = 0; i < 4; i++) {
		int num = 0;
		for (int j = 0; j < 4; j++)
			num += (int) (a[j % 4] * pow(10, (i + j) % 4));
		if (num < min)
			min = num;
	}
	return min;
}

int main() {
	int a[4];
	scanf("%d %d %d %d", &a[3], &a[2], &a[1], &a[0]);
	int cnt = 0;
	int input_clock = get_clock(a);

	for (int i = 1111; i <= input_clock; i++) {
		a[0] = i % 10;
		a[1] = (i / 10) % 10;
		a[2] = (i / 100) % 10;
		a[3] = i / 1000;
		bool is_containing_zero = false;
		for (int j = 0; j < 4; j++)
			is_containing_zero |= a[j] == 0;
		if (is_containing_zero || i != get_clock(a))
			continue;
		else 
			cnt++;
	}
	printf("%d\n", cnt);
}