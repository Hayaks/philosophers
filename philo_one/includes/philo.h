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
	long			time;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat_max;
	t_philosopher	*philo;
	pthread_mutex_t	message;
	pthread_mutex_t	end;
	pthread_mutex_t	*fork;
}				t_info;

typedef struct	s_philosopher
{
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				nb_eat_max;
	long			last_eat;
	long			time;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*message;
}				t_philosopher;

int				set_thread(t_info *info);
int				set_mutex(t_info *info);
t_info			*malloc_info(int ac, char **av);
int				set_info(t_info *info);
int				set_philo(t_info *info);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_error(t_info *info, char *str);
void			free_push(t_info *info);
long			actual_time(void);
void			message_philo(t_philosopher *philo, char *str);
void			philo_life(void *philo);
#endif