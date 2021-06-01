/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:50:50 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/01 22:51:07 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            if (full_all == info->nb_philo
            && info->nb_eat_max != -1)
		    {
			    message_end_eat(info);
			    return (NULL);
		    }
            i++;
		}
        if (full_all == info->nb_philo
        && info->nb_eat_max != -1)
		{
		    message_end_eat(info);
		    return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
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
		i = i + 2;
		usleep(50);
	}
	i = 1;
    usleep(50);
	while (i < info->nb_philo)
	{
        info->philo[i] = set_philo(info, i);
		if (pthread_create(&id, NULL, &philo_life, &info->philo[i]))
			return (1);
		pthread_detach(id);
		i = i + 2;
		usleep(50);
	}
    monitor(info);
	return (0);
}

int     set_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->message, NULL))
		return (1);
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->nb_philo);
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
	if (set_mutex(info))
		return (ft_error(info, "Error: Mutex \n"));
    info->philo = (t_philo *)malloc(sizeof(t_philo) * info->nb_philo);
	if (!info->philo)
		return (ft_error(info, "Error: malloc des philosophes \n"));
	if (set_thread(info))
		return (ft_error(info, "Error: Thread \n"));
    destroy_all_mutex(info);
	free_push(info);
}
