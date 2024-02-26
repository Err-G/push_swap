/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:04:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:42:38 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ps_sorted(t_ps *ps);

int	is_ps_sorted(t_ps *ps)
{
	if (ps->b->top > 0)
		return (1);
	return (stk_test(ps->a, _lth));
}
