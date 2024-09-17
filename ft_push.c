/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:00:33 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/17 11:42:02 by varodrig         ###   ########.fr       */
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

void	ft_pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(a, b);
	printf("pa\n");
}

void	ft_pb(t_stack_node **b, t_stack_node **a)
{
	ft_push(b, a);
	printf("pb\n");
}
