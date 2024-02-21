/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:10:30 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 12:32:05 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strtoi(char *str, int *err);
int		ft_count_args(int ac, char **av);
int		ft_get_args(t_stk **stk, int ac, char **av);
int		ft_check_dup(t_stk *stk);
t_ps	*ft_init(int ac, char **av);

int	ft_strtoi(char *str, int *err)
{
	size_t	i;
	size_t	res;
	int		sig;

	i = 0;
	res = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (++(*err));
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i++] - '0');
		if (res > INT_MAX)
			return (++(*err));
	}
	return (res * sig);
}

int	ft_count_args(int ac, char **av)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (++i < ac)
		wc += ft_wordcount(av[i], " \n");
	return (wc);
}

int	ft_get_args(t_stk **stk, int ac, char **av)
{
	int		i;
	int		err;
	char	*tok;

	i = 0;
	err = 0;
	*stk = stk_new(ft_count_args(ac, av));
	if (!*stk)
		return (1);
	while (++i < ac)
	{
		tok = ft_strtok(av[i], " \n");
		while (tok)
		{
			stk_push(*stk, ft_strtoi(tok, &err));
			tok = ft_strtok(NULL, " \n");
		}
	}
	return (err);
}

int	ft_check_dup(t_stk *stk)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= stk->top)
	{
		j = -1;
		while (++j < i)
			if (stk->dat[j] == stk->dat[i])
				return (1);
	}
	return (0);
}

t_ps	*ft_init(int ac, char **av)
{
	t_ps	*res;
	t_stk	*stk;
	int		err;

	res = ps_new(ft_count_args(ac, av));
	err = ft_get_args(&stk, ac, av);
	if (!stk || !res)
	{
		stk_del(stk);
		ps_del(res);
		return (NULL);
	}
	err += ft_check_dup(stk);
	if (err)
	{
		ft_printf("Error\n");
		stk_del(stk);
		return (ps_del(res));
	}
	while (stk->top >= 0)
		stk_push(res->a, stk_pop(stk));
	stk_del(stk);
	return (res);
}