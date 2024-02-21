/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:06:34 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 15:44:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stk	t_stk;
typedef struct s_ps		t_ps;

struct	s_stk
{
	int	*dat;
	int	top;
	int	cap;
};

struct	s_ps
{
	t_stk	*a;
	t_stk	*b;
};

/* STK */
/* stk.c */
t_stk	*stk_new(int cap);
void	*stk_del(t_stk *stk);
void	stk_push(t_stk *stk, int val);
int		stk_pop(t_stk *stk);
int		stk_getpos(t_stk *stk, int pos);

/* stk_op.c */
void	stk_print(t_stk *stk);
void	stk_swap(t_stk *stk);
void	stk_rot(t_stk *stk);
void	stk_rrot(t_stk *stk);

/* PS */
/* ps.c */
t_ps	*ps_new(int cap);
void	*ps_del(t_ps *ps);
void	ps_print(t_ps *ps);
void	ps_exec(t_ps *ps, char *cmd);
void	ps_execp(t_ps *ps, char *cmd);

/* ps_pushswap.c */
void	ps_pa(t_ps *ps);
void	ps_pb(t_ps *ps);
void	ps_sa(t_ps *ps);
void	ps_sb(t_ps *ps);
void	ps_ss(t_ps *ps);

/* ps_rot.c */
void	ps_ra(t_ps *ps);
void	ps_rb(t_ps *ps);
void	ps_rr(t_ps *ps);

/* ps_rrot.c */
void	ps_rra(t_ps *ps);
void	ps_rrb(t_ps *ps);
void	ps_rrr(t_ps *ps);

/* UTILS */
/* init.c */
int		ft_strtoi(char *str, int *err);
int		ft_count_args(int ac, char **av);
int		ft_get_args(t_stk **stk, int ac, char **av);
int		ft_check_dup(t_stk *stk);
t_ps	*ft_init(int ac, char **av);

/* sort_less.c */
void	sort_less(t_ps *ps);

/* sort_more.c */

/* sort.c */
void	sort(t_ps *ps);

/* stack_test.c */
int		is_stk_sorted(t_stk *stk, int (*cmp)(int, int));
int		is_ps_sorted(t_ps *ps);

/* tests.c */
int		test_lth(int a, int b);
int		test_gth(int a, int b);
int		test_min(int a, int b);
int		test_max(int a, int b);

#endif
