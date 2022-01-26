#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/time.h>
int main(int argc, char **argv) {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("%ld%d\n" ,tv.tv_sec , tv.tv_usec);
	gettimeofday(&tv, NULL);
	printf("%ld%d\n", tv.tv_sec, tv.tv_usec);
	return 0;
}
