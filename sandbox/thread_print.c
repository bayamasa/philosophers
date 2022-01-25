#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <pthread.h>

void *thread_func_1(void *param)
{
	usleep(10000);
	printf("kita thread func 1\n");
		return (0);
}


void *thread_func_2(void *param)
{
	usleep(10000);
	printf("kita thread func 2\n");
	return (0);
}

int main(void) {

	pthread_t thread;
	int ret = 0;

	// スレッドの作成
	// int pthread_create(pthread_t * thread, pthread_attr_t * attr,
	//                    void * (*start_routine)(void *), void * arg)
	// 第4引数に渡した値が、スレッド関数の引数に渡される
	ret = pthread_create(&thread, NULL, thread_func_1, NULL);
	if (ret != 0) {
		// pthread_createが失敗した場合は0以外の値を返す
		exit(1);
	}

	ret = pthread_create(&thread, NULL, thread_func_2, NULL);
	if (ret != 0) {
		// pthread_createが失敗した場合は0以外の値を返す
		exit(1);
	}

	// スレッドの終了を待機
	int pthread_join(pthread_t th, void **thread_return);
	printf("join mae\n");
	ret = pthread_join(thread, NULL);
	if (ret != 0) {
		// pthread_joinが失敗した場合は0以外の値を返す
		exit(1);
	}
	printf("join ato\n");
	
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


