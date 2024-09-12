/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:08:41 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/12 18:49:02 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_param_a(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_cost(a, b);
}

void	init_param_b(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_b(a, b);
}

static void	prep_for_push(t_stack_node **head, t_stack_node *cheapest_node,
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

void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node, 'b');
	pb(b, a);
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	//b is already ready
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	min_on_top(t_stack_node **a)
{
	
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_length(*a);
	// pb two times
	if (len_a-- > 3 && !stack_sorted(*a))
		ft_pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		ft_pb(b, a);
	// pb the cheapest
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_param_a(*a, *b);
		push_a_to_b(a, b);
	}
	ft_tiny_sort(a);
	while (*b)
	{
		// b is sorted so we dont need costs (except the smalest that are on top)
		init_param_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_position(*a);
	min_on_top(a);
}
