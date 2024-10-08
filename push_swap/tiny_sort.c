/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:34:03 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:41:36 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_stack_node **a)
{
	t_stack_node	*max;

	max = find_max_node(*a);
	if (*a == max)
		ft_ra(a, true);
	else if ((*a)->next == max)
		ft_rra(a, true);
	if ((*a)->x > (*a)->next->x)
		ft_sa(a, true);
}
