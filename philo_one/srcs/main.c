#include "../includes/philo.h"

int main(int ac, char **av)
{
	t_info    *info;

	info = NULL;
	info = malloc_info(ac, av);
	if (!info)
		return (ft_error(info, "Error: malloc \n"));
	if (ac != 5 && ac != 6)
		return (ft_error(info, "Error: wrong numbers of arguments \n"));
	if (set_info(info))
		return (1);
	free_push(info);
}