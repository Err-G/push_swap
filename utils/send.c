/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:31:21 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:35:00 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_ps *ps);
void	send_to_a(t_ps *ps);

void	send_to_b(t_ps *ps)
{
	int	rb_need;

	rb_need = calc_atob(ps);
	otmz_rot_ab(ps, 0, rb_need);
	ps_execp(ps, "pb");
}

void	send_to_a(t_ps *ps)
{
	if (stk_getpos(ps->a, 0) < stk_getpos(ps->b, 0))
		ps_execp(ps, "pa");
}
