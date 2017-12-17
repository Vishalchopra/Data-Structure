#include <stdio.h>

#define SIZE 5

char A[] = "";
void binaryString(int);
int main()
{
	printf("array before recursion %s\n", A);
	binaryString(SIZE);

	return 0;
}

void binaryString(int size)
{
	if (size < 1)
		printf("%s\n", A);
	else {
		A[size - 1] = '0';
		binaryString(size - 1);
		A[size - 1] = '1';
		binaryString(size - 1);
	}

}
