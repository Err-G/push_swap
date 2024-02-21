/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:39:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 12:32:18 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ps_new(int cap);
void	*ps_del(t_ps *ps);
void	ps_print(t_ps *ps);
void	ps_exec(t_ps *ps, char *cmd);
void	ps_execp(t_ps *ps, char *cmd);

t_ps	*ps_new(int cap)
{
	t_ps	*res;

	res = (t_ps *)ft_calloc(1, sizeof(t_ps));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	res->a = stk_new(cap);
	res->b = stk_new(cap);
	if (!res->a || !res->b)
		return (ps_del(res));
	return (res);
}

void	*ps_del(t_ps *ps)
{
	stk_del(ps->a);
	stk_del(ps->b);
	free(ps);
	return (NULL);
}

void	ps_print(t_ps *ps)
{
	ft_printf("a: ");
	stk_print(ps->a);
	ft_printf("b: ");
	stk_print(ps->b);
}

void	ps_exec(t_ps *ps, char *cmd)
{
	char	**cmds;
	void	(**ops)(t_ps *);
	int		i;

	i = -1;
	cmds = (char *[]){"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra",
		"rrb", "rrr"};
	ops = (void (*[])(t_ps *)){ps_pa, ps_pb, ps_sa, ps_sb, ps_ss, ps_ra, ps_rb,
		ps_rr, ps_rra, ps_rrb, ps_rrr};
	while (++i <= 11)
	{
		if (ft_strncmp(cmds[i], cmd, ft_strlen(cmd)) == 0)
		{
			ops[i](ps);
			return ;
		}
	}
}

void	ps_execp(t_ps *ps, char *cmd)
{
	ps_exec(ps, cmd);
	ft_printf("%s\n", cmd);
}
