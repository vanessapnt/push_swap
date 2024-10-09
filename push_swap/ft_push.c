/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:00:33 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:49:50 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*top_dest;
	t_stack_node	*top_src;

	if (dest && src && (*src))
	{
		top_dest = *dest;
		top_src = *src;
		if (top_src->next)
			top_src->next->prev = NULL;
		*src = top_src->next;
		top_src->next = top_dest;
		if (top_dest)
			top_dest->prev = top_src;
		*dest = top_src;
	}
}

void	ft_pa(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack_node **b, t_stack_node **a, bool print)
{
	ft_push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
