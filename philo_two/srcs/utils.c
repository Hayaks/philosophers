#include "../includes/philo.h"

static int	ft_nb_size(int nb)
{
	int	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

static int	ft_nombre(int nbr, int nb)
{
	if (nbr < 0)
		nb = nbr * -1;
	else
		nb = nbr;
	return (nb);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		nb;
	int		index;
	int		size;

	nb = 0;
	nb = ft_nombre(nbr, nb);
	index = 0;
	size = ft_nb_size(nb);
	if (!(str = malloc(sizeof(*str) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		str[index] = (char)(nb % 10 + 48);
		index--;
		nb = nb / 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
