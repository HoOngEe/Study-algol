#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	int tc_count;
	char fst[100];
	char snd[100];

	scanf("%d", &tc_count);
	for (int i = 0; i < tc_count; i++) {
		int hamming = 0;
		scanf("%s", fst);
		scanf("%s", snd);
		for (unsigned int j = 0; j < strlen(fst); j++) {
			if (fst[j] != snd[j])
				hamming++;
		}
		printf("Hamming distance is %d.\n", hamming);
	}
}