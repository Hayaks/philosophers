/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:50:50 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/31 00:10:52 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    monitor(t_info *info)
{
	int     end;
    int		full_all;
	long    time;
    int		i;

	end = 0;
	while (end != 1)
	{
        full_all = 0;
        time = actual_time();
		i = 0;
		while (i < info->nb_philo)
		{
			if ((int)(time - info->philo[i].last_eat) > info->t_die)
				return (handle_death(info, info->philo[i]));
			if (info->philo[i]->full_all == 1)
				full_all++;
            i++;
		}
        if (full_all == info->nb_philo)
				return (handle_end_meal(info));
		usleep(1000);
	}
	return (NULL);
}

int	    set_thread(t_info *info)
{
	pthread_t	id;
	int			i;

	i = 0;
	while (i < info->nb_philo)
	{
		usleep(50);
        set_philo(info, philo, i);
		if (pthread_create(&id, NULL, &philo_life, &info->philo[i]))
			return (1);
		pthread_detach(id);
		i = i + 2;
	}
	i = 1;
	while (i < info->nb_philo)
	{
		usleep(50);
        set_philo(info, philo, i);
		if (pthread_create(&id, NULL, &philo_life, &info->philo[i]))
			return (1);
		pthread_detach(id);
		i = i + 2;
	}
    monitor(info);
	/*if (pthread_create(&info->id_monitor, NULL, &monitor, &info)
			return (1);
	pthread_detach(info->id_monitor);*/
	return (0);
}

int	    set_mutex(t_info *info)
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

int	    main(int ac, char **av)
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
	//set_philo(info, philo, i);
	if (set_thread(info))
		return (ft_error(info, "Error: Thread \n"));
	//pthread_mutex_lock(&info.end);
    destroy_all_mutex(info);
	free_push(info);
}