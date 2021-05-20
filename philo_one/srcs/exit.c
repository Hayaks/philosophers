#include "../includes/philo.h"

void	ft_free_push(t_info *info)
{
	if (info)
		free(info);
}

int	ft_error(t_info *info, char *str)
{
	ft_free_push(info);
	write(2, str, ft_strlen(str));
	return (1);
}