/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:37:19 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/13 15:38:53 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

# include "utils/stack/stack.h"
# include "utils/ps/ps.h"

/* Other */
int		ft_strtoi(char *str, int *error);
int		ft_count_args(int ac, char **av);
int		ft_get_args(t_stack **stk, int ac, char **av);
t_ps	*ft_init(int ac, char **av);
int		ft_check_dup(t_stack *stk);

#endif
