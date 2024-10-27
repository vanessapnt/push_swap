/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:30 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/24 13:47:54 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	handle_split(char *argv, t_stack_node **a)
{
	char	**split_result;
	int		i;

	split_result = ft_split(argv, ' ');
	if (!split_result)
		ft_error();
	init_stack_a_split(a, split_result);
	i = 0;
	while (split_result[i])
		free(split_result[i++]);
	free(split_result);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		ft_error();
	else if (argc == 2)
		handle_split(argv[1], &a);
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (ft_stack_length(a) == 2)
			ft_sa(&a, true);
		else if (ft_stack_length(a) == 3)
			ft_tiny_sort(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
