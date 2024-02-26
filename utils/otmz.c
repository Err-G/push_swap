/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otmz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:23:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/26 01:31:03 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		otmz_rot_a(t_ps *ps, int r_times);
int		otmz_rot_b(t_ps *ps, int r_times);
void	otmz_rot_ab(t_ps *ps, int ra_times, int rb_times);

int	otmz_rot_a(t_ps *ps, int r_times)
{
	int	times;

	times = r_times;
	while (r_times)
	{
		if (r_times > 0)
		{
			ps_execp(ps, "ra");
			r_times--;
		}
		else if (r_times < 0)
		{
			ps_execp(ps, "rra");
			r_times++;
		}
	}
	return (times);
}

int	otmz_rot_b(t_ps *ps, int r_times)
{
	int	times;

	times = r_times;
	while (r_times)
	{
		if (r_times > 0)
		{
			ps_execp(ps, "rb");
			r_times--;
		}
		else if (r_times < 0)
		{
			ps_execp(ps, "rrb");
			r_times++;
		}
	}
	return (times);
}

void	otmz_rot_ab(t_ps *ps, int ra_times, int rb_times)
{
	while (ra_times || rb_times)
	{
		if (ra_times > 0 && rb_times > 0)
		{
			ps_execp(ps, "rr");
			ra_times--;
			rb_times--;
		}
		else if (ra_times < 0 && rb_times < 0)
		{
			ps_execp(ps, "rrr");
			ra_times++;
			rb_times++;
		}
		else
		{
			ra_times -= otmz_rot_a(ps, ra_times);
			rb_times -= otmz_rot_b(ps, rb_times);
		}
	}
}
