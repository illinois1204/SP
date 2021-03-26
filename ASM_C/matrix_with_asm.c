#include <stdio.h>

extern void MatrixFill(int, int*);

int main()
{
    const int n = 11;
	printf("Array\tsize=%d\n", n);
    int Matrix[n*n];
    MatrixFill(n, Matrix);

    for (char i = 0; i < n*n; i+=n)
    {
        for (char j = 0; j < n; j++)
        {
            printf("%d  ", Matrix[i+j]);
        }
        printf("\n");
    }
	return 0;
}
