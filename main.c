/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:35:54 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/10 15:52:44 by ecarvalh         ###   ########.fr       */
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

void	sort(t_ps *ps)
{
	int	i;

	if (is_sorted(ps)) {
		ft_printf("OK\n");
		return ;
	}
	i = ps->a->top + 1;
	if (i == 3)
	{
		if (stack_getn(ps->a, 0) < stack_getn(ps->a, 1))
	}
	ft_printf("KO\n");
}

/*
1 2 3:   1 < 2 < 3: [correct]
2 1 3:   2 > 1 < 3: sa
2 3 1:   2 < 3 > 1: rra
3 1 2:   3 > 1 < 2: ra
1 3 2:   1 < 3 > 2: rra sa
3 2 1:   3 > 2 > 1: ra sa

ra  <-
rra ->
sa  ><

if (arr[top] > arr[top - 1])
{
	if (arr[top - 1] < arr[top - 2])
	{
		
	}
}
*/
/*
typedef enum e_op t_ope;
enum e_op {
	OP_SA, OP_RA, OP_RRA,
	OP_SB, OP_RB, OP_RRB,
	OP_SS, OP_RS, OP_RRR,
	OP_PA, OP_PB
};
op = {
	ps_sa, ps_ra, ps_rra,
	ps_sb, ps_rb, ps_rrb,
	ps_ss, ps_rr, ps_rrr,
	ps_pa, ps_pb };
names = {
	"sa\n", "ra\n", "rra\n",
	"sb\n", "rb\n", "rrb\n",
	"ss\n", "rr\n", "rrr\n",
	"pa\n", "pb\n" };
*/

int	get_arg(t_ps **ps, char **av)
{
	int		i;
	int		error;
	char	**res;

	error = 0;
	res = ft_split(av[1], ' ');
	if (!res)
		return (1);
	i = -1;
	while (res[++i])
		;
	*ps = ps_new(i);
	i = -1;
	while (res[++i])
	{
		stack_push((*ps)->a, ft_strtoi(res[i], &error));
		free(res[i]);
	}
	free(res);
	return (error);
}

int	get_args(t_ps **ps, int ac, char **av)
{
	int	i;
	int	error;

	error = 0;
	*ps = ps_new(ac - 1);
	if (!ps)
		return (1);
	i = ac;
	while (--i > 0)
		stack_push((*ps)->a, ft_strtoi(av[i], &error));
	return (error);
}

int	main(int ac, char **av)
{
	t_ps	*ps;
	int		error;

	error = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		error += get_arg(&ps, av);
	else
		error += get_args(&ps, ac, av);
	error += ft_check_dup(ps);
	if (error)
	{
		ft_printf("Error\n");
		ps_del(ps);
		return (1);
	}
	sort(ps);
	//stack_print(ps->a, "a");
	ps_del(ps);
	return (0);
}
