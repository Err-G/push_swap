/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:39:45 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 15:39:56 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_args(t_stack **stk, int ac, char **av)
{
	int		i;
	int		error;
	char	*tok;

	i = 0;
	error = 0;
	*stk = stack_new(ft_count_args(ac, av));
	if (!*stk)
		return (1);
	while (++i < ac)
	{
		tok = ft_strtok(av[i], " \n");
		while (tok)
		{
			stack_push(*stk, ft_strtoi(tok, &error));
			tok = ft_strtok(NULL, " \n");
		}
	}
	return (error);
}
