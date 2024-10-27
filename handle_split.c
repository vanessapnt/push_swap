/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:23:43 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/21 18:52:42 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_errors_split(t_stack_node **a, char **split)
{
	int	i;

	ft_free_stack(a);
	i = 0;
	while (split[i])
		i++;
	while (i)
		free(split[--i]);
	free(split);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_stack_a_split(t_stack_node **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors_split(a, argv);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors_split(a, argv);
		if (error_double(*a, (int)nb))
			free_errors_split(a, argv);
		add_node(a, (int)nb);
		i++;
	}
}
