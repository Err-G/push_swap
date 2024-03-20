/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:31:21 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/20 16:20:08 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_ps *ps);
void	send_to_a(t_ps *ps);

/*
void	send_to_b(t_ps *ps)
{
	int	ra_need;
	int	rb_need;

	ra_need = calc_min_atob(ps);
	rb_need = calc_atob(ps, stk_getpos(ps->a, ra_need));
	otmz_rot_ab(ps, ra_need, rb_need);
	ps_execp(ps, "pb");
}
*/

void	send_to_b(t_ps *ps)
{
	ps_execp(ps, "pb");
	if (stk_getpos(ps->b, 0) < ps->b->cap / 2)
		ps_execp(ps, "rb");
}

void	send_to_a(t_ps *ps)
{
	int	rb_need;
	int	ra_need;

	rb_need = calc_min_btoa(ps);
	ra_need = calc_btoa(ps, stk_getpos(ps->b, rb_need));
	otmz_rot_ab(ps, ra_need, rb_need);
	ps_execp(ps, "pa");
}
