/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:08:41 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/21 14:10:22 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_members_a(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_a(a, b);
	set_cost(a, b);
}

void	init_members_b(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_b(a, b);
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
	prep_for_push(b, cheapest_node->target, 'b');
	ft_pb(b, a);
}

//b is already ready
void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	ft_pa(a, b);
}

//pb two times
//pb the cheapest
//b is sorted (except the smalest that are on top) so we dont need costs
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_length(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		ft_pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		ft_pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_members_a(*a, *b);
		push_a_to_b(a, b);
	}
	ft_tiny_sort(a);
	while (*b)
	{
		init_members_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_position(*a);
	min_on_top(a);
}
