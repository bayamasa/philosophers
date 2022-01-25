#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>

void *thread_func_1(void *param)
{
	int *stat = (int *)param;
	printf("*stat in func 1 before = %d\n", *stat);
	*stat = true;
	printf("kita thread func 1\n");
		return (0);
}


void *thread_func_2(void *param)
{
	int *stat = (int *)param;
	// ここの時点でstatusは1になっているから、影響を及ぼしている。
	printf("*stat in func 2 before = %d\n", *stat);
	*stat = true;
	printf("kita thread func 2\n");
	return (0);
}

int main(void) {

	pthread_t thread;
	int ret = 0;
	int	status = false;

	// スレッドの作成
	// int pthread_create(pthread_t * thread, pthread_attr_t * attr,
	//                    void * (*start_routine)(void *), void * arg)
	// 第4引数に渡した値が、スレッド関数の引数に渡される
	ret = pthread_create(&thread, NULL, thread_func_1, &status);
	if (ret != 0) {
		// pthread_createが失敗した場合は0以外の値を返す
		exit(1);
	}
	printf("status = %d\n", status);
	ret = pthread_create(&thread, NULL, thread_func_2, &status);
	if (ret != 0) {
		// pthread_createが失敗した場合は0以外の値を返す
		exit(1);
	}
	printf("status = %d\n", status);

	// スレッドの終了を待機
	// int pthread_join(pthread_t th, void **thread_return);
	printf("join mae\n");
	printf("status = %d\n", status);
	ret = pthread_join(thread, NULL);
	if (ret != 0) {
		// pthread_joinが失敗した場合は0以外の値を返す
		exit(1);
	}
	printf("join ato\n");
	printf("status = %d\n", status);
	// // スレッドの終了を待たない
	// printf("detach before\n");
	// // int pthread_detach(pthread_t th)
	// ret = pthread_detach(thread);
	// if (ret != 0) {
	// 	// pthread_detachが失敗した場合は0以外の値を返す
	// 	exit(1);
	// }
	// printf("detach after\n");

	return EXIT_SUCCESS;
	}


