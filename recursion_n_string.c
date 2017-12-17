#include <stdio.h>

#define SIZE 5

char A[] = "";
void binaryString(int, int);
int main()
{
	printf("array before recursion %s\n", A);
	binaryString(SIZE, 3);

	return 0;
}

void binaryString(int size, int k)
{
	if (size < 1)
		printf("%s\n", A);
	else {
		for (int j = 0; j < k; j++){
			A[size - 1] =  (48 + j);
			binaryString(size-1, k);
		}
	}

}
