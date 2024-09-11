/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:36:31 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/11 13:48:14 by varodrig         ###   ########.fr       */
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

int	ft_stack_length(t_stack_node *head)
{
	int			len;
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

void	ft_print_stack(t_stack_node *a)
{
	t_stack_node	*curr;

	curr = a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
}
