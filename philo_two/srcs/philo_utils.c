#include "../includes/philo.h"

void	*message_end_eat(t_info *info)
{
	pthread_mutex_lock(&info->message);
	printf("end of simulation\n");
	return (NULL);
}

void	message_philo(t_philo philo, char *str)
{
	pthread_mutex_lock(philo.message);
	printf("%ld %d %s\n", (actual_time() - philo.time), philo.id, str);
	pthread_mutex_unlock(philo.message);
}

long	actual_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
