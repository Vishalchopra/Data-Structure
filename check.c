#include <stdio.h>


int main()
{

	int a=10, b=5, c=6, d;
	d = (a ^ b ^ c);
	printf("%d \n", d);
	d = d ^ a ^ b;;
	printf("%d \n", d);

	return 0;
}
