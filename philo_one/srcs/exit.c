/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:50:54 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/07 14:26:54 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (info->fork)
		free(info->fork);
	info->fork = NULL;
	if (info->philo)
		free(info->philo);
	info->philo = NULL;
	if (info)
		free(info);
	info = NULL;
}

int	ft_error(t_info *info, char *str)
{
	free_push(info);
	write(2, str, ft_strlen(str));
	return (1);
}
