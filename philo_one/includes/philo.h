#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_info
{
	int				ac;
	char			**av;
	int             time;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
}				t_info;

t_info 			*malloc_info(int ac, char **av);
int				set_info(t_info *info);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_error(t_info *info, char *str);
void			ft_free_push(t_info *info);
#endif