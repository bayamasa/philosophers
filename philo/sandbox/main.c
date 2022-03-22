#include "../includes/philo.h"

int main()
{
	t_philo_attr *s;
	
	s = (t_philo_attr *)malloc(sizeof(t_philo_attr));
	if (s->ph_attr == NULL)
	{
		//segv
		printf("kita\n");
	}
	s->ph_attr = (t_philo_attr **)malloc(sizeof(t_philo_attr *));
	system("leaks a.out");
	return 0;
}
