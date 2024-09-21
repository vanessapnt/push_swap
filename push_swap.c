/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:30 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/21 13:52:33 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_result;
	int				i;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
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
	if (!stack_sorted(a))
	{
		if (ft_stack_length(a) == 2)
			ft_sa(&a);
		else if (ft_stack_length(a) == 3)
			ft_tiny_sort(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
