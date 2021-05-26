#include "../includes/philo.h"

long    actual_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}