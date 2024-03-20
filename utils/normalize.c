/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:36:28 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/20 16:02:29 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	normalize_pop(t_stk *stk)
{
	static int	popped = 0;
	int			pos;
	int			res;
	int			value;

	pos = -1;
	res = 0;
	value = stk_getpos(stk, popped);
	while (++pos < stk->top)
		if (stk_getpos(stk, pos) < value)
			res++;
	popped++;
	return (res);
}
