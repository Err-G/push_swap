/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:23:02 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/09 22:53:21 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

typedef struct s_ps		t_ps;
struct	s_ps
{
	t_stack	*a;
	t_stack	*b;
};

t_ps	*ps_new(int capacity);
void	ps_del(t_ps *ps);

void	ps_ra(t_ps *ps); /* rotate a */
void	ps_rb(t_ps *ps); /* rotate b */
void	ps_rr(t_ps *ps); /* rotate all */

void	ps_rra(t_ps *ps); /* reverse rotate a */
void	ps_rrb(t_ps *ps); /* reverse rotate b */
void	ps_rrr(t_ps *ps); /* reverse rotate all */

void	ps_sa(t_ps *ps); /* swap a */
void	ps_sb(t_ps *ps); /* swap b */
void	ps_ss(t_ps *ps); /* swap all */

void	ps_pa(t_ps *ps); /* push a */
void	ps_pb(t_ps *ps); /* push b */

#endif
