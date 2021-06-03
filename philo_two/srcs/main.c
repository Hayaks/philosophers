#include "../includes/philo.h"

void    *monitor(t_info *info)
{
    int		full_all;
	long    time;
    int		i;

	while (1)
	{
        full_all = 0;
        time = actual_time();
		i = 0;
		while (i < info->nb_philo)
		{
			if ((int)(time - info->philo[i].last_eat) > info->t_die)
			{
				message_philo(info->philo[i], "died");
				return (NULL);
			}
			if (info->philo[i].full == 1)
				full_all++;
            i++;
		}
        if (full_all == info->nb_philo
        && info->nb_eat_max != -1)
		    return (message_end_eat(info));
		usleep(1000);
	}
}

int     set_thread(t_info *info)
{
	pthread_t	id;
	int			i;

	i = 0;
	while (i < info->nb_philo)
	{
        info->philo[i] = set_philo(info, i);
		if (pthread_create(&id, NULL, &philo_life, &info->philo[i]))
			return (1);
		pthread_detach(id);
		i++;
	}
    monitor(info);
	return (0);
}

int     main(int ac, char **av)
{
	t_info    *info;

	info = NULL;
	info = malloc_info(ac, av);
	if (!info)
		return (ft_error(info, "Error: malloc \n"));
	if (ac != 5 && ac != 6)
		return (ft_error(info, "Error: mauvais nombre d'arguments \n"));
	if (set_info(info))
		return (1);
    info->philo = (t_philo *)malloc(sizeof(t_philo) * info->nb_philo);
	if (!info->philo)
		return (ft_error(info, "Error: malloc des philosophes \n"));
	if (set_thread(info))
		return (ft_error(info, "Error: Thread \n"));
    destroy_all_sem(info);
	free_push(info);
}
