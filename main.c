/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:15:38 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 16:59:44 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_ps *ps)
{
	int	i;

	i = -1;
	if (ps->b->top >= 0)
		return (1);
	while (++i < ps->a->top)
	{
		if (stack_getn(ps->a, i) > stack_getn(ps->a, i + 1))
			return (0);
	}
	return (1);
}

void	ps_exec(t_ps *ps, char *cmd)
{
	char	**cmds;
	void	(**ops)(t_ps *);
	int		i;

	i = -1;
	cmds = (char *[]){
		"sa", "ra", "rra", "sb", "rb", "rrb", "ss", "rr", "rrr", "pa", "pb" };
	ops = (void (*[])(t_ps *)){
		ps_sa, ps_ra, ps_rra, ps_sb, ps_rb, ps_rrb, ps_ss, ps_rr, ps_rrr,
		ps_pa, ps_pb };
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

void	sort3(t_ps *ps)
{
	if (is_sorted(ps))
		return ;
	if (stack_getn(ps->a, 0) < stack_getn(ps->a, 1))
	{
		ps_execp(ps, "rra");
		if (!is_sorted(ps))
			ps_execp(ps, "sa");
	}
	else
	{
		if (stack_getn(ps->a, 0) < stack_getn(ps->a, 2))
			ps_execp(ps, "sa");
		else
			ps_execp(ps, "ra");
		if (!is_sorted(ps))
			ps_execp(ps, "sa");
	}
}

int	main(int ac, char **av)
{
	t_ps	*ps;

	if (ac < 2)
		return (0);
	ps = ft_init(ac, av);
	if (!ps)
		return (0);
	if (ps->a->top == 2)
		sort3(ps);
	else
		ft_printf("KO\n");
	stack_print(ps->a, "a");
	ps_del(ps);
	return (0);
}
