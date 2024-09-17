/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:08:27 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/17 11:42:18 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (head && *head && (*head)->next)
	{
		first_node = *head;
		last_node = find_last_node(*head);
		first_node->prev = last_node;
		last_node->prev->next = NULL;
		last_node->next = first_node;
		last_node->prev = NULL;
		*head = last_node;
	}
}

void	ft_rra(t_stack_node **a)
{
	ft_reverse_rotate(a);
	printf("rra\n");
}

void	ft_rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
	printf("rrb\n");
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	printf("rrr\n");
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		ft_rrr(a, b);
}
