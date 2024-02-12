/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:19 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/06 15:38:36 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup(t_ps *ps)
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
