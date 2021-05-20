#include "../includes/philo.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (str[i])
		nb = 0;
	return (nb * sign);
}