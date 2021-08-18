#include<cstdio>
int main() {
	const int in = 300;
	int out, save = 0, temp = 0;
	bool hard = false;
	for (int i = 1; i <= 12; i++) {
		scanf("%d", &out);
		if ((temp = temp + in - out) < 0) {
			printf("%d", -i);
			hard = true;
			break;
		}
		save += temp / 100 * 100;
		temp %= 100;
	}
	if (!hard) {
		save = save * 1.2 + temp;
		printf("%d", save);
	}
	return 0;
}
