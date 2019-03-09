#include<cstdio>
#include<cstring>

using namespace std;
const int switch_cnt_max = 100;

int main() {
	int switch_cnt;
	int student_cnt;
	scanf("%d", &switch_cnt);
	bool switch_state[switch_cnt_max + 1];

	for (int i = 1; i <= switch_cnt; i++) {
		int temp;
		scanf("%d", &temp);
		switch_state[i] = temp == 1 ? true : false;
	}

	scanf("%d", &student_cnt);
	for (int i = 0; i < student_cnt; i++) {
		int gender, number;
		scanf("%d %d", &gender, &number);

		if (gender == 1)
			for (int j = number; j <= switch_cnt; j += number) {
				switch_state[j] = !switch_state[j];
			}
		else {
			switch_state[number] = !switch_state[number];
			for (int j = 1; (number - j >= 1) && (number + j <= switch_cnt); j++) {
				if (switch_state[number - j] == switch_state[number + j]) {
					switch_state[number - j] = !switch_state[number - j];
					switch_state[number + j] = !switch_state[number + j];
				}
				else
					break;
			}
		}
	}

	for (int i = 1; i <= switch_cnt; i++) {
		if (switch_state[i] == true)
			printf("1 ");
		else
			printf("0 ");
		if (i % 20 == 0)
			printf("\n");
	}
}