/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:23:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/22 17:48:25 by ecarvalh         ###   ########.fr       */
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
	int	opt_ra_times;
	int	opt_rb_times;

	opt_ra_times = opt_indx(ra_times, ps->a->top);
	opt_rb_times = opt_indx(rb_times, ps->b->top);
	while (opt_ra_times || opt_rb_times)
	{
		if (opt_ra_times > 0 && opt_rb_times > 0)
		{
			ps_execp(ps, "rr");
			opt_ra_times--;
			opt_rb_times--;
		}
		else if (opt_ra_times < 0 && opt_rb_times < 0)
		{
			ps_execp(ps, "rrr");
			opt_ra_times++;
			opt_rb_times++;
		}
		else
		{
			opt_ra_times -= opt_rot_a(ps, opt_ra_times);
			opt_rb_times -= opt_rot_b(ps, opt_rb_times);
		}
	}
}
