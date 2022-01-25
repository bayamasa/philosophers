#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>


void	test(void)
{
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
	int i = 1;
}


int	main()
{
	int i;
	int *a;
	long *l;
	static char a;
	char *s;
	char c;

	// 未初期化変数の値は、不定。
	printf("i = %d\n", i);
	printf("*a = %d\n", *a);
	printf("s : %s\n", s);
	printf("c = %s\n", c);
	printf("l = %p\n", l);
	test();
	return (0);
}
