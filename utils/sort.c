/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:43:16 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:41:01 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less(t_ps *ps);
void	sort_more(t_ps *ps);
void	sort(t_ps *ps);

void	sort_less(t_ps *ps)
{
	int	pos0;
	int	pos1;
	int	pos2;

	if (stk_test(ps->a, _lth))
		return ;
	pos0 = stk_getpos(ps->a, 0);
	pos1 = stk_getpos(ps->a, 1);
	pos2 = stk_getpos(ps->a, 2);
	if (pos0 < pos1)
		ps_execp(ps, "rra");
	else if (pos0 < pos2)
		ps_execp(ps, "sa");
	else
		ps_execp(ps, "ra");
	if (!stk_test(ps->a, _lth))
		ps_execp(ps, "sa");
}

void	sort_more(t_ps *ps)
{
	if (ps->a->top > 3)
		ps_execp(ps, "pb");
	if (ps->a->top > 3)
		ps_execp(ps, "pb");
	while (ps->a->top > 3)
		send_to_b(ps);
	sort_less(ps);
	while (ps->b->top > 0)
		send_to_a(ps);
}

void	sort(t_ps *ps)
{
	if (ps->a->top >= 2 && ps->a->top <= 3)
		sort_less(ps);
	else
		sort_more(ps);
}
