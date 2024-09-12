/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:30 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/12 14:32:13 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char		**split_result;
	int			i;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		if (!split_result)
			exit(1);
		init_stack_a(&a, split_result);
		i = 0;
		while (split_result[i])
			i++;
		while (--i >= 0)
			free(split_result[i]);
		free(split_result);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_length(a) == 2)
			sa(&a);
		else if (ft_stack_length(a) == 3)
			ft_tiny_sort(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}

void	ft_free_stack(t_stack_node	**head)
{
	t_stack_node	*curr;

	if (*head == NULL)
		return;
	curr = *head;
	while (curr->next)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*head = NULL;
}

void	free_errors(t_stack_node **a)
{
	ft_free_stack(a);
	printf("Error\n");
	exit(1);
}

int	error_syntax(char *s)
{
	//first char must be '-', '+' or digit
	if (!(*s == '-' || *s == '+' || (*s >= '0' && *s <= '9')))
		return (1);
	//second char must be digit
	if ((*s == '-' || *s == '+') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	//only digits following
	while (++*s)
	{
		if (!(s[1] >= '0' && s[1] <= '9'))
			return (1);
	}
	return (0);
}

int	error_double(t_stack_node *a, int nb)
{
	t_stack_node	*curr;

	curr = a;
	while (curr)
	{
		if (curr->x == nb)
			return (1);
		curr = curr->next;
	}
	return (0);
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

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors(a);
		if (error_double(*a, (int)nb))
			free_errors(a);
		add_node(a, (int)nb);
		i++;
	}
}

//sort_stacks