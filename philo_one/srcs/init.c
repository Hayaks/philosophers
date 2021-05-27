#include "../includes/philo.h"

int		set_philo(t_info *info, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		philo[i]->id = i + 1;
		philo[i]->t_die = info->t_die;
		philo[i]->t_eat = info->t_eat;
		philo[i]->t_sleep = info->t_sleep;
		philo[i]->nb_eat = 0;
		philo[i]->nb_eat_max = info->nb_eat_max;
		philo[i]->fork_right = info->fork[i];
		philo[i]->last_eat = info->time;
		philo[i]->time = info->time;
		if (i != info->nb_philo)
			philo[i]->fork_left = info->fork[i + 1];
		else
			philo[i]->fork_left = info->fork[0];
		i++;
		philo[i]->message = info->message;
	}
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
	|| !info->t_sleep || !info->nb_eat-Max)
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
	info->message = NULL;
	info->end = NULL;
	return (info);
}