/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_hlpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:40:37 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:56:57 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_iter(t_stk *stk, int (*func)(int, int));
int	stk_test(t_stk *stk, int (*func)(int, int));
int	stk_find(t_stk *stk, int (*func)(int, int), int val);

int	stk_iter(t_stk *stk, int (*func)(int, int))
{
	int	pos;
	int	val;

	pos = 0;
	val = stk_getpos(stk, pos);
	while (++pos < stk->top)
		val = func(val, stk_getpos(stk, pos));
	return (val);
}

int	stk_test(t_stk *stk, int (*func)(int, int))
{
	int	pos;

	pos = 0;
	while (++pos < stk->top)
		if (!func(stk_getpos(stk, pos - 1), stk_getpos(stk, pos)))
			return (0);
	return (1);
}

int	stk_find(t_stk *stk, int (*func)(int, int), int val)
{
	int	pos;

	pos = -1;
	while (++pos < stk->top)
		if (func(stk_getpos(stk, pos), val))
			break ;
	return (pos);
}
