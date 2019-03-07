#include<cstdio>
#include<cassert>

using namespace std;
typedef char Digit;
Digit carry = 0;
const int base = 10;
const int max_len = 2001;

class Number {
public:
	bool n_sign = false;
	Digit digits[max_len] = { 0 };
	int len = 0;
	Number& negate();
};

Number& Number::negate() {
	this->n_sign = !this->n_sign;
	return *this;
}

Number add(Number&, Number&);
Number subtract(Number&, Number&);
void print_Number(Number& a);

Digit add(Digit a, Digit b) {
	Digit result = a + b;
	carry = result / base;
	return result % base;
}

Digit subtract(Digit a, Digit b) {
	Digit result = a - b;
	if (result < 0) {
		carry = -1;
		return result + base;
	}
	else {
		carry = 0;
		return result;
	}
}

Digit multiply(Digit a, Digit b) {
	Digit result = a * b;
	carry = result / base;
	return result % base;
}

Digit from_char(char a) {
	return a - '0';
}

Number add(Number& fst, Number& snd) {
	carry = 0;
	if (fst.n_sign == true && snd.n_sign == true)
		return add(fst.negate(), snd.negate()).negate();
	else if (fst.n_sign == true && snd.n_sign == false)
		return subtract(snd, fst.negate());
	else if (fst.n_sign == false && snd.n_sign == true)
		return subtract(fst, snd.negate());
	else {
		Number result;
		Digit* fst_digits = fst.digits;
		Digit* snd_digits = snd.digits;
		int i;
		for (i = 0; i < fst.len || i < snd.len; i++) {
			result.digits[i] = add(fst_digits[i] + carry, snd_digits[i]);
		}
		result.digits[i] = add(fst_digits[i] + carry, snd_digits[i]);
		result.len = i;
		if (result.digits[i] != 0)
			result.len++;

		return result;
	}
}

int compare_and_trim(Number& fst, Number& snd, int pos) {
	assert(fst.n_sign == false && snd.n_sign == false);
	if (pos == -1)
		return -1;
	if (fst.len > snd.len)
		return 1;
	else if (fst.len < snd.len)
		return 0;
	else if (fst.digits[pos] == snd.digits[pos]) {
		fst.len--; fst.digits[pos] = 0;
		snd.len--; snd.digits[pos] = 0;
		return compare_and_trim(fst, snd, pos - 1);
	}
	else 
		return fst.digits[pos] > snd.digits[pos] ? 1 : 0;
}

Number subtract(Number& fst, Number& snd) {
	carry = 0;
	if (fst.n_sign == true && snd.n_sign == true)
		return subtract(snd.negate(), fst.negate());
	else if (fst.n_sign == true && snd.n_sign == false)
		return add(fst.negate(), snd).negate();
	else if (fst.n_sign == false && snd.n_sign == true)
		return add(fst, snd.negate());
	else {
		int compare_result = compare_and_trim(fst, snd, fst.len - 1);
		if (compare_result == 1) {
			Number result;
			Digit* fst_digits = fst.digits;
			Digit* snd_digits = snd.digits;
			int i;
			for (i = 0; i < fst.len || i < snd.len; i++) {
				result.digits[i] = subtract(fst_digits[i] + carry, snd_digits[i]);
			}
			result.len = i;
			if (result.digits[i-1] == 0)
				result.len--;

			return result;
		}
		else if (compare_result == 0) {
			return subtract(snd, fst).negate();
		}
		else {
			Number result;
			result.len = 1;
			return result;
		}
	}
}

Number multiply(Number& fst, Number& snd) {
	if (fst.n_sign == true && snd.n_sign == true)
		return multiply(fst.negate(), snd.negate());
	else if (fst.n_sign == true && snd.n_sign == false)
		return multiply(snd, fst.negate()).negate();
	else if (fst.n_sign == false && snd.n_sign == true)
		return multiply(fst, snd.negate()).negate();
	else {
		Number total_result;
		Digit* fst_digits = fst.digits;
		Digit* snd_digits = snd.digits;
		int i,j, prev_total_carry = 0;
		int add_carry = 0, mul_carry = 0;

		total_result.len = 0;
		total_result.n_sign = false;
		for (i = 0; i < snd.len; i++) {
			Number temp_result;
			prev_total_carry = 0;
			for (j = 0; j < fst.len; j++) {
				temp_result.digits[i + j] = multiply(fst_digits[j], snd_digits[i]);
				mul_carry = carry;
				temp_result.digits[i + j] = add(temp_result.digits[i + j], prev_total_carry);
				add_carry = carry;
				prev_total_carry = add_carry + mul_carry;
			}
			temp_result.digits[i + j] = (Digit)prev_total_carry;
			temp_result.len = i + j;
			if (temp_result.digits[i + j])
				temp_result.len++;
			total_result = add(total_result, temp_result);
		}
		return total_result;
	}
}

int get_digits(char buf[], bool& n_sign) {
	int i = 0;
	char input;
	while (true) {
		scanf("%c", &input);
		if (input == '\n')
			break;
		if (input == '-')
			n_sign = true;
		else {
			buf[i] = input;
			i++;
		}
	}
	return i;
}

void rearrange(Digit digits[], char buf[], int len) {
	for (int i = 0; i < len; i++) {
		digits[i] = from_char(buf[len - i - 1]);
	}
	return;
}

void print_Number(Number& a) {
	//special case
	if (a.digits[a.len - 1] == 0) {
		printf("0\n");
		return;
	}
	if (a.n_sign == true)
		printf("-");
	for (int i = 0; i < a.len; i++) {
		printf("%d", a.digits[a.len - 1 - i]);
	}
	printf("\n");
}

int main() {
	Number target[2];
	for (int i = 0; i < 2; i++) {
		char buf[1000] = { 0 };
		bool n_sign = false;
		int len = get_digits(buf, n_sign);
		target[i].len = len;
		target[i].n_sign = n_sign;
		rearrange(target[i].digits, buf, len);
	}
	Number targetCopied[4];
	targetCopied[0] = target[0];
	targetCopied[1] = target[1];
	targetCopied[2] = target[0];
	targetCopied[3] = target[1];

	Number added = add(target[0], target[1]);
	Number multiplied = multiply(targetCopied[0], targetCopied[1]);
	Number subtracted = subtract(targetCopied[2], targetCopied[3]);
	
	print_Number(added);
	print_Number(subtracted);
	print_Number(multiplied);
}
