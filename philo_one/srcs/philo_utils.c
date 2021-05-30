/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:51:18 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/30 22:51:20 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	message_philo(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(philo->message);
	printf("%ld %d %s\n", (actual_time() - philo->time), philo->id, str);
	pthread_mutex_unlock(philo->message);
}

long	actual_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}