/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:36:28 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/19 17:40:12 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	normalize_pop(t_stk *stk)
{
	int	pos;
	int	res;

	pos = -1;
	res = 0;
	while (++pos < stk->top)
		if (stk_getpos(stk, pos) < stk_getpos(stk, -1))
			res++;
	return (res);
}
