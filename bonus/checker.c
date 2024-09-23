/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:26 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:53:18 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	handle_split(char *argv, t_stack_node **a)
{
	char	**split_result;
	int		i;

	split_result = ft_split(argv, ' ');
	if (!split_result)
		exit(1);
	init_stack_a(a, split_result);
	i = 0;
	while (split_result[i])
		free(split_result[i++]);
	free(split_result);
}

static void	ft_checker(char *str, t_stack_node **a, t_stack_node **b)
{
	char	*commands[11];
	int		command_index;

	init_commands(commands);
	str = get_next_line(0);
	while (str)
	{
		command_index = ft_strcmp(commands, str);
		if (command_index > -1)
			execute_command(command_index, a, b);
		else
		{
			printf("Error\n");
			break ;
		}
		str = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;
	char			*str;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		handle_split(argv[1], &a);
	else
		init_stack_a(&a, argv + 1);
	ft_checker(str, &a, &b);
	if (!b && (stack_sorted(a)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&a);
	return (0);
}
