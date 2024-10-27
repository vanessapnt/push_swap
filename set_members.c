/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_members.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:06 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/21 16:56:10 by varodrig         ###   ########.fr       */
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

//target = closest smaller, if not max
void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*reset_b;
	t_stack_node	*target;
	t_stack_node	*max;
	t_stack_node	*min;

	reset_b = b;
	if (!b)
		return ;
	max = find_max_node(b);
	min = find_min_node(b);
	while (a)
	{
		target = min;
		while (b)
		{
			if ((b->x < a->x) && (b->x > target->x))
				target = b;
			b = b->next;
		}
		if (target->x > a->x)
			target = max;
		b = reset_b;
		a->target = target;
		a = a->next;
	}
}

//target = the closest bigger, if not min
void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*reset_a;
	t_stack_node	*target;
	t_stack_node	*min;
	t_stack_node	*max;

	reset_a = a;
	if (!a)
		return ;
	min = find_min_node(a);
	max = find_max_node(a);
	while (b)
	{
		target = max;
		while (a)
		{
			if ((a->x > b->x) && (a->x < target->x))
				target = a;
			a = a->next;
		}
		if (target->x < b->x)
			target = min;
		a = reset_a;
		b->target = target;
		b = b->next;
	}
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
