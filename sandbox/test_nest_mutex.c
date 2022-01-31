#include "../philo/includes/philo.h"

// mutexに別のmutexをネストしたらエラーが発生するのか
// 特に問題なさそう

typedef struct t_mutex
{
	pthread_mutex_t test_1;
	pthread_mutex_t test_2;
	int				status;
}	m;

void *test_1(void *params)
{
	m *p;
	p = (m *)params;
	pthread_mutex_lock(&(p->test_1));
	printf("test_1 kita\n");
	sleep(1);
	pthread_mutex_lock(&(p->test_2));
	sleep(1);
	p->status = 100;
	pthread_mutex_unlock(&(p->test_2));
	printf("p->status test_1 = %d\n", p->status);
	pthread_mutex_unlock(&(p->test_1));
	return (NULL);
}

void *test_2(void *params)
{
	m *p;
	p = (m *)params;
	pthread_mutex_lock(&(p->test_1));
	printf("test_2 kita\n");
	sleep(1);
	p->status = 111;
	printf("p->status test_2 = %d\n", p->status);
	pthread_mutex_unlock(&(p->test_1));
	return (NULL);
}



int	main()
{
	pthread_t	thread_1;
	pthread_t	thread_2;

	m	params;
	
	params.status = 100;
	pthread_mutex_init(&params.test_1, NULL);
	pthread_mutex_init(&params.test_2, NULL);

	if (pthread_create(&thread_1, NULL, test_1, &params) != 0)
	{
		printf("dame\n");
	}

	usleep(50);
	if (pthread_create(&thread_2, NULL, test_2, &params) != 0)
	{
		printf("dame\n");
	}
	//
	sleep(7);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	return (0);
}