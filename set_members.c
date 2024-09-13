/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_members.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:06 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/13 14:38:08 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_cheapest(t_stack_node *a)
{
	t_stack_node	*cheapest;

	cheapest = a;
	while (a)
	{
		if ((a->push_cost) < (cheapest->push_cost))
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*reset_b;
	t_stack_node	*target;
	t_stack_node	*max;

	reset_b = b;
	if (!b)
		return ;
	max = find_max_node(b);
	while (a)
	{
		target = max;
		while (b)
		{
			if ((b->x > target->x) && (b->x <= a->x))
				target = b;
			b = b->next;
		}
		b = reset_b;
		a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
}

void	set_position(t_stack_node *head)
{
	int	i;
	int	median;

	i = 0;
	median = ft_stack_length(head) / 2;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
		i++;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	price;
	int	len_a;
	int	len_b;

	len_a = ft_stack_length(a);
	len_b = ft_stack_length(b);
	while (a)
	{
		if (a->above_median == true)
			a->push_cost = a->index;
		else
			a->push_cost = len_a - a->index;
		if (a->target->above_median == true)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}