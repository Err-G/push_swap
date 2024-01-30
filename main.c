/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:35:54 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/30 18:09:05 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_ps *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= ps->a->top)
	{
		j = -1;
		while (++j < i)
			if (ps->a->data[j] == ps->a->data[i])
				return (1);
	}
	return (0);
}

int	is_sorted(t_ps *ps)
{
	int	i;

	i = -1;
	if (ps->b->top >= 0)
		return (1);
	while (++i < ps->a->top)
	{
		if (ps->a->data[i] < ps->a->data[i + 1])
			return (0);
	}
	return (1);
}

void	sort(t_ps *ps)
{
	int	i;

	if (is_sorted(ps))
		return ;
	i = ps->a->top;
	ft_printf("KO\n");
}

/*
1 2 3: 1 < 2 < 3 = correct
2 1 3: 2 > 1 < 3: sa
2 3 1: 2 < 3 > 1: rra
3 1 2: 3 > 1 < 2: ra
1 3 2: 1 < 3 > 2: rra sa
3 2 1: 3 > 2 > 1: ra sa

ra  <-
rra ->
sa  ><
*/

int	get_arg(t_ps *ps, int ac, char **av)
{
	auto int i = -1;
	auto int error = 0;
	auto char **res = NULL;
	if (ac == 2)
	{
		res = ft_split(av[1], ' ');
		if (!res)
			return (1);
		while (res[++i])
		{
			push(ps->a, ft_strtoi(res[i], &error));
			free(res[i]);
		}
		free(res);
	}
	else
	{
		i = ac;
		while (--i > 0)
			push(ps->a, ft_strtoi(av[i], &error));
	}
	return (error);
}

int	main(int ac, char **av)
{
	t_ps	*ps;
	int		error;

	error = 0;
	if (ac < 2)
		return (0);
	ps = ps_new(ac - 1);
	if (!ps)
		return (1);
	error += get_arg(ps, ac, av);
	error += check_duplicate(ps);
	if (error)
	{
		ft_printf("Error\n");
		ps_del(ps);
		return (1);
	}
	stack_print(ps->a, "a");
// 1 3 2: 1 < 3 > 2: ra
	ps_ra(ps);
//	sort(ps);
	stack_print(ps->a, "a");
	ps_del(ps);
	return (0);
}

/*
stack_print(ps->a, "a");
stack_print(ps->b, "b");
*/
