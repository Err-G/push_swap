/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:23:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/22 19:27:53 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		opt_indx(int idx, int max);
int		opt_rot_a(t_ps *ps, int r_times);
int		opt_rot_b(t_ps *ps, int r_times);
void	opt_rot_ab(t_ps *ps, int ra_times, int rb_times);

int	opt_indx(int idx, int max)
{
	if (idx <= max / 2)
		return (idx);
	else
		return (idx - max);
}

int	opt_rot_a(t_ps *ps, int r_times)
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

int	opt_rot_b(t_ps *ps, int r_times)
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

void	opt_rot_ab(t_ps *ps, int ra_times, int rb_times)
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
			ra_times -= opt_rot_a(ps, ra_times);
			rb_times -= opt_rot_b(ps, rb_times);
		}
	}
}
