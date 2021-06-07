/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:34:03 by jsaguez           #+#    #+#             */
/*   Updated: 2021/06/07 18:34:23 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				nb_eat_max;
	int				full;
	long			last_eat;
	long			time;
	sem_t			*fork;
	sem_t			*message;
}				t_philo;

typedef struct s_info
{
	int				ac;
	char			**av;
	long			time;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat_max;
	t_philo			*philo;
	sem_t			*message;
	sem_t			*fork;
}				t_info;

int				set_mutex(t_info *info);
int				set_thread(t_info *info);
void			*monitor(t_info *info);
t_info			*malloc_info(int ac, char **av);
int				set_info(t_info *info);
t_philo			set_philo(t_info *info, int i);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int nbr);
int				ft_error(t_info *info, char *str);
void			free_push(t_info *info);
void			destroy_all_sem(t_info *info);
long			actual_time(void);
void			message_philo(t_philo philo, char *str);
void			*message_end_eat(t_info *info);
void			*philo_life(void *philo);
t_philo			philo_eat(t_philo philo, t_philo *point);
void			philo_sleep_and_think(t_philo philo);
void			low_sleep(long time);
#endif