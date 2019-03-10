#include<cstdio>

using namespace std;
#define MOD 1000000000
#define period 1500000000

// fibonacci sequence sum from F_1 to F_n 
// is equal to F_(n+2) - 1
long long int a, b, c, d;

void fast_fibo(long long int n, long long int ans[]) {
	if (n == 0) {
		ans[0] = 0;
		ans[1] = 1;
		return;
	}
	fast_fibo((n / 2), ans);
	a = ans[0];             /* F(n) */
	b = ans[1];             /* F(n+1) */
	c = 2 * b - a;
	if (c < 0)
		c += MOD;
	c = (a * c) % MOD;      /* F(2n) */
	d = (a*a + b * b) % MOD;  /* F(2n + 1) */
	if (n % 2 == 0) {
		ans[0] = c;
		ans[1] = d;
	}
	else {	
		ans[0] = d;
		ans[1] = c + d;
	}
}


int main() {
	long long a, b;
	long long int ans[2] = { 0 };
	long long result1, result2;
	long long answer;

	scanf("%lld %lld", &a, &b);
	fast_fibo((b + 2) % period, ans);
	result1 = ans[0];
	fast_fibo((a + 1) % period, ans);
	result2 = ans[0];

	answer = result1 > result2 ? result1 - result2 : result1 + MOD - result2;
	printf("%lld\n", answer);
}