/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:55:09 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/24 13:49:23 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max_node(t_stack_node *head)
{
	t_stack_node	*curr;
	t_stack_node	*max;

	curr = head;
	max = curr;
	while (curr)
	{
		if (curr->x > max->x)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

t_stack_node	*find_min_node(t_stack_node *head)
{
	t_stack_node	*curr;
	t_stack_node	*min;

	curr = head;
	min = curr;
	while (curr)
	{
		if (curr->x < min->x)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	t_stack_node	*curr;

	curr = head;
	if (curr)
	{
		while (curr->next)
			curr = curr->next;
	}
	return (curr);
}

int	ft_stack_length(t_stack_node *head)
{
	int				len;
	t_stack_node	*curr;

	len = 0;
	curr = head;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}
/*
void	ft_print_stack(t_stack_node *a)
{
	t_stack_node	*curr;
	int				i;

	curr = a;
	while (curr != NULL)
	{
		i = curr->x;
		ft_putnbr_fd(i, 1);
		curr = curr->next;
	}
}
*/
