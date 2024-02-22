/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:46:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/22 20:02:12 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_atob(t_ps *ps, int a_pos);
int		find_min_atob(t_ps *ps);
void	sort_more(t_ps *ps);

int	find_atob(t_ps *ps, int a_pos)
{
	int	i;

	i = 0;
	if ((stk_getpos(ps->a, a_pos) > stk_getpos(ps->b, 0))
		&& (stk_getpos(ps->a, a_pos) < stk_getpos(ps->b, ps->b->top)))
		return (0);
	while (++i <= ps->b->top)
		if ((stk_getpos(ps->a, a_pos) > stk_getpos(ps->b, i))
			&& (stk_getpos(ps->a, a_pos) < stk_getpos(ps->b, i - 1)))
			break ;
	return (opt_indx(i, ps->b->top));
}

/*
4 5 6
1 2 3
*/

int	find_min_atob(t_ps *ps)
{
	int	i;
	int	min;
	int	min_pos;
	int	cost;

	i = 0;
	cost = find_atob(ps, 0);
	min = cost;
	min_pos = 0;
	while (++i <= ps->a->top)
	{
		cost = find_atob(ps, i);
		if (opt_indx(i, ps->a->top) + cost < min)
		{
			min = opt_indx(i, ps->a->top) + cost;
			min_pos = i;
		}
	}
	return (min_pos);
}

void	sort_more(t_ps *ps)
{
	int	ra_times;
	int	rb_times;

	ps_execp(ps, "pb");
	ps_execp(ps, "pb");
	while (ps->a->top + 1 >= 3)
	{
		ra_times = opt_indx(find_min_atob(ps), ps->a->top);
		rb_times = find_atob(ps, find_min_atob(ps));
		ps_print(ps);
		ft_printf("ra: %d, rb: %d\n", ra_times, rb_times);
		opt_rot_ab(ps, ra_times, rb_times);
		ps_execp(ps, "pb");
	}
}
