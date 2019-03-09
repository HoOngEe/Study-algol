#include<cstdio>
#include<cstring>

using namespace std;

int main() {
	char a[1000];
	char b[1000];
	scanf("%s", a);
	scanf("%s", b);
	if (strlen(a) >= strlen(b))
		printf("go");
	else
		printf("no");
}