/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:56:12 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 17:24:43 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_ps_check(t_ps *ps, char *cmd)
{
	char	**cmds;
	void	(**ops)(t_ps *);
	int		i;

	i = -1;
	cmds = (char *[]){"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n",
		"rr\n", "rra\n", "rrb\n", "rrr\n"};
	ops = (void (*[])(t_ps *)){ps_pa, ps_pb, ps_sa, ps_sb, ps_ss, ps_ra, ps_rb,
		ps_rr, ps_rra, ps_rrb, ps_rrr};
	while (++i <= 11)
	{
		if (ft_strncmp(cmds[i], cmd, ft_strlen(cmd)) == 0)
		{
			ops[i](ps);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	auto t_ps * ps = ft_init(ac, av);
	auto char *line = ft_getline_fd(0);
	auto int err = 0;
	while (line)
	{
		if (exec_ps_check(ps, line))
		{
			err = ft_printf("Error\n");
			break ;
		}
		free(line);
		line = ft_getline_fd(0);
	}
	if (!err)
	{
		if (is_ps_sorted(ps))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free(line);
	ps_del(ps);
	return (0);
}
