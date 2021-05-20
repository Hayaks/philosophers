#include "../includes/philo.h"

int main(int ac, char **av)
{
	t_info    *info;

	info = NULL;
	info = (t_info*)malloc(sizeof(t_info));
	if (!info)
		return (ft_error(info, "Error: malloc \n"));
	if (malloc_info(info, ac, av))
		return (1);
	if (ac != 5 && ac != 6)
		return (ft_error(info, "Error: wrong numbers of arguments \n"));
	if (set_info(info))
		return (1);
	ft_free_push(info);
}