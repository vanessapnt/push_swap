/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:43:38 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/21 18:47:46 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// first char must be '-', '+' or digit
// second char must be digit
// only digits following

int	error_syntax(char *s)
{
	if (!(*s == '-' || *s == '+' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '-' || *s == '+') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
		s++;
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

static void	free_errors(t_stack_node **a)
{
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(char *str)
{
	long	nb;
	long	even;

	nb = 0;
	even = 1;
	if (*str == '-')
	{
		even = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		nb = nb * 10 + (*str++ - '0');
	}
	nb = nb * even;
	return (nb);
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
