/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:31:21 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 12:04:22 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_ps *ps);
void	send_to_a(t_ps *ps);

void	send_to_b(t_ps *ps)
{
	int	ra_need;
	int	rb_need;

	ra_need = calc_min_atob(ps);
	rb_need = calc_atob(ps, stk_getpos(ps->a, ra_need));
	otmz_rot_ab(ps, ra_need, rb_need);
	ps_execp(ps, "pb");
}

void	send_to_a(t_ps *ps)
{
	int	ra_need;

	ra_need = calc_btoa(ps, stk_getpos(ps->b, 0));
	otmz_rot_ab(ps, ra_need, 0);
	ps_execp(ps, "pa");
}
