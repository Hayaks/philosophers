/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:18:53 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/07 18:34:44 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_all_sem(t_info *info)
{
	sem_close(info->fork);
	sem_close(info->message);
	sem_unlink("fork");
	sem_unlink("message");
}

void	free_push(t_info *info)
{
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
