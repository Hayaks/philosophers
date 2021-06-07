/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:18:35 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/07 18:18:36 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	low_sleep(long time)
{
	long	wait;

	wait = actual_time() + time;
	while (actual_time() < wait)
		usleep(time);
}

void	philo_sleep_and_think(t_philo philo)
{
	message_philo(philo, "is sleeping");
	low_sleep(philo.t_sleep);
	message_philo(philo, "is thinking");
}

t_philo	philo_eat(t_philo philo, t_philo *point)
{
	sem_wait(philo.fork);
	message_philo(philo, "as taken a fork");
	message_philo(philo, "as taken a fork");
	message_philo(philo, "is eating");
	point->last_eat = actual_time();
	low_sleep(philo.t_eat);
	sem_post(philo.fork);
	point->nb_eat++;
	if (point->nb_eat != 1 && point->nb_eat >= point->nb_eat_max)
		point->full = 1;
	return (philo);
}

void	*philo_life(void *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (1)
	{
		philo_eat(*tmp, tmp);
		philo_sleep_and_think(*tmp);
	}
	return (NULL);
}
