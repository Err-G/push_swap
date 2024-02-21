/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:16:59 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 15:45:18 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less(t_ps *ps);

void	sort_less(t_ps *ps)
{
	if (is_stk_sorted(ps->a, test_lth))
		return ;
	if (stk_getpos(ps->a, 0) < stk_getpos(ps->a, 1))
		ps_execp(ps, "rra");
	else if (stk_getpos(ps->a, 0) < stk_getpos(ps->a, ps->a->top))
		ps_execp(ps, "sa");
	else
		ps_execp(ps, "ra");
	if (!is_stk_sorted(ps->a, test_lth))
		ps_execp(ps, "sa");
}
