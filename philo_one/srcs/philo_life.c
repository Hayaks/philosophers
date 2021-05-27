#include "../includes/philo.h"

void	philo_sleep_and_think(t_philosopher *philo)
{
	message_philo(philo, "is sleeping");
	usleep(philo->t_sleep * 1000);
	message_philo(philo, "is thinking");
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_right);
	message_philo(philo, "as taken a fork");
	pthread_mutex_lock(philo->fork_left);
	message_philo(philo, "as taken a fork");
	message_philo(philo, "is eating");
	philo->nb_eat++;
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void	philo_life(void *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (NULL);
}