#include <stdio.h>

int main() {
	int arr[] = {535, 3768, -243, 927, 980, 2043, 5484, 875, -94, 7234};
	int edge = 1488;
	int Sum = 0, Count = 0;

	for (char i = 0; i < 10; i++) {
		if (arr[i] > edge)
			Sum += arr[i];
		else
			Count++;
	}
	printf("%d %d\n", Sum, Count);
	return 0;
}
