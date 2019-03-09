#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	char input;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%c", &input);
			if ((i + j) % 2 == 0 && input == 'F')
				cnt++;
		}
		scanf("%c", &input);
	}
	printf("%d\n", cnt);
}