/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:46:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/22 17:47:24 by ecarvalh         ###   ########.fr       */
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
	return (i);
}

/*
1 4 5 6
2 3
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
		ft_printf("total cost: %d, index: %d\n", cost + i, i);
		if (i + cost < min)
		{
			min = i + cost;
			min_pos = i;
		}
	}
	return (min_pos);
}

void	sort_more(t_ps *ps)
{
	int	ra_times;
	int	rb_times;

	ra_times = find_min_atob(ps);
	rb_times = find_atob(ps, ra_times);
	ps_execp(ps, "pb");
	ps_execp(ps, "pb");
//	ft_printf("ra_times: %d, rb_times: %d\n", ra_times, rb_times);
	opt_rot_ab(ps, ra_times, rb_times);
}
