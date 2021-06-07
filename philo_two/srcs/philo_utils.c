/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:18:28 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/07 18:18:29 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*message_end_eat(t_info *info)
{
	sem_wait(info->message);
	printf("end of simulation\n");
	return (NULL);
}

void	message_philo(t_philo philo, char *str)
{
	sem_wait(philo.message);
	printf("%ld %d %s\n", (actual_time() - philo.time), philo.id, str);
	sem_post(philo.message);
}

long	actual_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
