/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:35:54 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/28 22:46:46 by ecarvalh         ###   ########.fr       */
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
	if (is_sorted(ps))
		return ;

	ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	int		i;
	t_ps	*ps;
	int		error;

	error = 0;
	if (ac < 2)
		return (0);
	ps = ps_new(ac - 1);
	if (!ps)
		return (1);
	i = ac;
	while (--i > 0)
		push(ps->a, ft_strtoi(av[i], &error));
	error += check_duplicate(ps);
	if (error)
	{
		ft_printf("Error\n");
		ps_del(ps);
		return (1);
	}
	/*
	stack_print(ps->a, "a");
	stack_print(ps->b, "b");
	*/
	sort(ps);
	ps_del(ps);
	return (0);
}
