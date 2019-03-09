#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int fst = num / 10;
	int snd = num % 10;

	int target_fst = fst;
	int target_snd = snd;
	int temp, i = 0;

	do {
		temp = (fst + snd) % 10;
		fst = snd;
		snd = temp;
		i++;
	} while (target_fst != fst || target_snd != snd);

	printf("%d\n", i);
}