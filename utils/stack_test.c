/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:04:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 12:10:39 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_stk_sorted(t_stk *stk, int (*cmp)(int, int));
int		is_ps_sorted(t_ps *ps);

int	is_stk_sorted(t_stk *stk, int (*cmp)(int, int))
{
	int	i;

	i = -1;
	while (++i < stk->top)
		if (!cmp(stk_getpos(stk, i), stk_getpos(stk, i + 1)))
			return (0);
	return (1);
}

int	is_ps_sorted(t_ps *ps)
{
	if (ps->b->top >= 0)
		return (1);
	return (is_stk_sorted(ps->a, test_lth));
}
