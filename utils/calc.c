/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:46:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 12:27:08 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rot(t_stk *stk, int stk_size);
int	calc_atob(t_ps *ps, int a_val);
int	calc_min_atob(t_ps *ps);

int	calc_rot(t_stk *stk, int rot)
{
	if (rot <= stk->top / 2)
		return (rot);
	return (rot - stk->top);
}

int	calc_atob(t_ps *ps, int a_val)
{
	int	i;
	int	b_val;
	int	prev_b;

	if (!ps->b->top)
		return (0);
	i = -1;
	prev_b = stk_getpos(ps->b, -1);
	if (a_val > stk_iter(ps->b, _max) || a_val < stk_iter(ps->b, _min))
		return (calc_rot(ps->b, stk_find(ps->b, _equ, stk_iter(ps->b, _max))));
	while (++i < ps->b->top)
	{
		b_val = stk_getpos(ps->b, i);
		if (a_val > b_val && a_val < prev_b)
			break ;
		prev_b = b_val;
	}
	return (calc_rot(ps->b, i));
}

int	calc_btoa(t_ps *ps, int b_val)
{
	int	i;
	int	a_val;
	int	prev_a;

	if (!ps->a->top)
		return (0);
	i = -1;
	prev_a = stk_getpos(ps->a, -1);
	if (b_val > stk_iter(ps->a, _max) || b_val < stk_iter(ps->a, _min))
		return (calc_rot(ps->a, stk_find(ps->a, _equ, stk_iter(ps->a, _min))));
	while (++i < ps->a->top)
	{
		a_val = stk_getpos(ps->a, i);
		if (b_val < a_val && b_val > prev_a)
			break ;
		prev_a = a_val;
	}
	return (calc_rot(ps->a, i));
}

int	calc_min_atob(t_ps *ps)
{
	int	i;
	int	cost;
	int	total_cost;
	int	min_cost;
	int	min_pos;

	i = -1;
	min_pos = 0;
	min_cost = _abs(calc_atob(ps, stk_getpos(ps->a, 0)));
	while (++i < ps->a->top)
	{
		cost = _abs(calc_atob(ps, stk_getpos(ps->a, i)));
		total_cost = cost + _abs(calc_rot(ps->a, i));
		min_cost = _min(total_cost, min_cost);
		if (min_cost == total_cost)
			min_pos = i;
	}
	return (calc_rot(ps->a, min_pos));
}
