/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:08:27 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:51:55 by varodrig         ###   ########.fr       */
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

void	ft_rra(t_stack_node **a, bool print)
{
	ft_reverse_rotate(a);
	if (printf)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack_node **b, bool print)
{
	ft_reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		ft_rrr(a, b, true);
}
