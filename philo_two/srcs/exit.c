#include "../includes/philo.h"

void	destroy_all_mutex(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->message);
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
}

void	free_push(t_info *info)
{
	if (info->philo)
		free(info->philo);
	if (info->fork)
		free(info->fork);
	if (info)
		free(info);
}

int		ft_error(t_info *info, char *str)
{
	free_push(info);
	write(2, str, ft_strlen(str));
	return (1);
}
