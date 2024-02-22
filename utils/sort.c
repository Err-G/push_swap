/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:43:16 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/21 16:45:40 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *ps);

void	sort(t_ps *ps)
{
	int	len;

	len = ps->a->top + 1;
	if (len >= 1 && len <= 3)
		sort_less(ps);
	else
		sort_more(ps);
}
