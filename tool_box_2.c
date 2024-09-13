/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:54:55 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/13 14:13:28 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *a)
{
	t_stack_node	*curr;

	if (a == NULL)
		return (1);
	curr = a;
	while (curr->next)
	{
		if (curr->next->x < curr->next)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	ft_free_stack(t_stack_node **head)
{
	t_stack_node	*curr;

	if (*head == NULL)
		return ;
	curr = *head;
	while (curr->next)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*head = NULL;
}

void	add_node(t_stack_node **a, int nb)
{
	t_stack_node	*new_node;

	new_node->x = nb;
	new_node->prev = NULL;
	if (*a)
	{
		new_node->next = *a;
		(*a)->prev = new_node;
	}
	else
		new_node->next = NULL;
	*a = new_node;
}
void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min_node(*a);
	while (*a != min)
		ft_rra(a);
}
void	prep_for_push(t_stack_node **head, t_stack_node *cheapest_node,
		char stack_name)
{
	while (*head != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ft_ra(head);
			else
				ft_rra(head);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				ft_rb(head);
			else
				ft_rrb(head);
		}
	}
}