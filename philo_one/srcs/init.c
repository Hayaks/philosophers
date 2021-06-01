/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:51:07 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/01 22:23:37 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	set_philo(t_info *info, int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.t_eat = info->t_eat;
	philo.t_sleep = info->t_sleep;
	philo.nb_eat = 0;
	philo.nb_eat_max = info->nb_eat_max;
	philo.full = 0;
	philo.last_eat = info->time;
	philo.time = info->time;
	philo.fork_right = &info->fork[i];
	if (philo.id != info->nb_philo)
		philo.fork_left = &info->fork[i + 1];
	else
		philo.fork_left = &info->fork[0];
	philo.message = &info->message;
	return (philo);
}

int		set_info(t_info *info)
{
	info->time = actual_time();
	info->nb_philo = ft_atoi(info->av[1]);
	info->t_die = ft_atoi(info->av[2]);
	info->t_eat = ft_atoi(info->av[3]);
	info->t_sleep = ft_atoi(info->av[4]);
	if (info->av[5])
		info->nb_eat_max = ft_atoi(info->av[5]);
	else
		info->nb_eat_max = -1;
	if (!info->nb_philo || !info->t_die || !info->t_eat
	|| !info->t_sleep || !info->nb_eat_max)
		return (ft_error(info, "Error: bad arguments \n"));
	return (0);
}

t_info	*malloc_info(int ac, char **av)
{
	t_info    *info;

	info = NULL;
	info = (t_info*)malloc(sizeof(t_info));
	if (!info)
		return NULL;
	info->ac = ac;
	info->av = av;
	info->time = 0;
	info->nb_philo = 0;
	info->t_die = 0;
	info->t_eat = 0;
	info->t_sleep = 0;
	info->nb_eat_max = 0;
	info->philo = NULL;
	info->fork = NULL;
	return (info);
}
