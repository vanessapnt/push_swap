/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:11:56 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:52:59 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack_node **head)
{
	t_stack_node	*node1;
	t_stack_node	*node2;

	if (head != NULL && *head != NULL && (*head)->next != NULL)
	{
		node1 = (*head);
		node2 = (*head)->next;
		node1->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = node1;
		node1->prev = node2;
		node2->prev = NULL;
		node2->next = node1;
		*head = node2;
	}
}

void	ft_sa(t_stack_node **a, bool print)
{
	ft_swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack_node **b, bool print)
{
	ft_swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		write(1, "ss\n", 3);
}
