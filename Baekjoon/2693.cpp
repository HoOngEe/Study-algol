#include<cstdio>

using namespace std;

int main() {
	int tc_count;
	scanf("%d", &tc_count);
	int k;
	int fst, snd, trd;

	for (int i = 0; i < tc_count; i++) {
		fst = 0; snd = 0; trd = 0;
		for (int j = 0; j < 10; j++) {
			scanf("%d", &k);
			if (k >= fst) {
				trd = snd; snd = fst; fst = k;
			}
			else if (k >= snd) {
				trd = snd; snd = k;
			}
			else if (k >= trd) {
				trd = k;
			}
		}
		printf("%d\n", trd);
	}
}