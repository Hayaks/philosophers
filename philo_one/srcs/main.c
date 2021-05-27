#include "../includes/philo.h"

int	set_thread(t_info *info)
{
	pthread_t	id;
	int			i;

	i = 0;
	while (i < info->nb_philo)
	{
		usleep(50);
		if (pthread_create(&id, NULL, &philo_life, &info->philo[i]))
			return (1);
		pthread_detach(id);
		i = i + 2;
	}
	i = 1;
	while (i < info->nb_philo)
	{
		usleep(50);
		if (pthread_create(&id, NULL, &philo_life, &info->philo[i]))
			return (1);
		pthread_detach(id);
		i = i + 2;
	}
	if (pthread_create(&info->id_monitor, NULL, &monitor, &info)
			return (1);
	pthread_detach(info->id_monitor);
	return (0);
}

int	set_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->message, NULL))
		return (1);
	if (pthread_mutex_init(&info->end, NULL))
		return (1);
	pthread_mutex_lock(&info->end);
	info->fork = (info->fork*)malloc(sizeof(info->fork) * info->nb_philo);
	if (!info->fork)
		return (ft_error(info, "Error: malloc des fourchettes \n"));
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
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
	if (set_mutex(info))
		return (ft_error(info, "Error: Mutex \n"));
    info->philo = (info->philo*)malloc(sizeof(info->philo) * info->nb_philo);
	if (!info->philo)
		return (ft_error(info, "Error: malloc des philosophes \n"));
	set_philo(info);
	if (set_thread(info))
		return (ft_error(info, "Error: Thread \n"));
	pthread_mutex_lock(&arg.end);
	free_push(info);
}