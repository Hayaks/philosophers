#include "../includes/philo.h"

void	free_push(t_info *info)
{
	if (info->fork)
		free(info->fork);
	if (info->philo)
		free(info->philo);
	if (info)
		free(info);
}

int		ft_error(t_info *info, char *str)
{
	free_push(info);
	write(2, str, ft_strlen(str));
	return (1);
}