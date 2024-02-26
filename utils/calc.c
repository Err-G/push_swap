/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:46:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:34:32 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rot(t_stk *stk, int stk_size);
int	calc_atob(t_ps *ps);

int	calc_rot(t_stk *stk, int rot)
{
	if (rot <= stk->top / 2)
		return (rot);
	return (rot - stk->top);
}

int	calc_atob(t_ps *ps)
{
	int	i;
	int	a_value;
	int	b_value;
	int	prev_b;

	if (!ps->b->top)
		return (0);
	i = -1;
	a_value = stk_getpos(ps->a, 0);
	prev_b = stk_getpos(ps->b, -1);
	if (a_value > stk_iter(ps->b, _max) || a_value < stk_iter(ps->b, _min))
		return (calc_rot(ps->b, stk_find(ps->b, _equ, stk_iter(ps->b, _max))));
	while (++i < ps->b->top)
	{
		b_value = stk_getpos(ps->b, i);
		if (a_value > b_value && a_value < prev_b)
			break ;
		prev_b = b_value;
	}
	return (calc_rot(ps->b, i));
}
