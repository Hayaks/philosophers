#include "../includes/philo.h"

int     set_info(t_info *info)
{
	//info->time?
	info->nb_philo = ft_atoi(info->av[1]);
	info->t_die = ft_atoi(info->av[2]);
	info->t_eat = ft_atoi(info->av[3]);
	info->t_sleep = ft_atoi(info->av[4]);
	if (info->av[5])
		info->nb_eat = ft_atoi(info->av[5]);
	else
		info->nb_eat = -1;
	if (!info->nb_philo || !info->t_die || !info->t_eat
	|| !info->t_sleep || !info->nb_eat)
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
	info->nb_eat = 0;
	return (info);
}