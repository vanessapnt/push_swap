/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:01:54 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:52:23 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (head && *head && (*head)->next)
	{
		first_node = *head;
		last_node = find_last_node(*head);
		last_node->next = first_node;
		*head = first_node->next;
		(*head)->prev = NULL;
		first_node->next = NULL;
		first_node->prev = last_node;
	}
}

void	ft_ra(t_stack_node **a, bool print)
{
	ft_rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack_node **b, bool print)
{
	ft_rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		ft_rr(a, b, true);
}
