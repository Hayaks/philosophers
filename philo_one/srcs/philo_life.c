#include "../includes/philo.h"

void	philo_sleep_and_think(t_philosopher *philo)
{
	message_philo(philo, "is sleeping");
	usleep(philo->t_sleep * 1000);
	message_philo(philo, "is thinking");
}

void	philo_eat(t_philosopher *philo)
{

}

void	philo_life(void *philo)
{
	while (1)
	{
		//eat
		//sleep
		//think
	}
	return (NULL);
}