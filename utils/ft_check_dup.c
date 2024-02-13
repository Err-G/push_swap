/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:37:19 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 15:24:18 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup(t_stack *stk)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= stk->top)
	{
		j = -1;
		while (++j < i)
			if (stk->data[j] == stk->data[i])
				return (1);
	}
	return (0);
}
