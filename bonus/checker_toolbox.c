/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:46 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 13:54:07 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_commands(char **commands)
{
	commands[0] = "sa\n";
	commands[1] = "ss\n";
	commands[2] = "sb\n";
	commands[3] = "pa\n";
	commands[4] = "pb\n";
	commands[5] = "ra\n";
	commands[6] = "rb\n";
	commands[7] = "rra\n";
	commands[8] = "rrb\n";
	commands[9] = "rr\n";
	commands[10] = "rrr\n";
}

int	ft_strcmp(char **commands, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (commands[i])
	{
		j = 0;
		while (str[j] && commands[i][j] && str[j] == commands[i][j])
			j++;
		if (str[j] == '\0' && commands[i][j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

void	execute_command(int command_index, t_stack_node **a, t_stack_node **b)
{
	if (command_index == 0)
		ft_sa(a, false);
	else if (command_index == 1)
		ft_ss(a, b, false);
	else if (command_index == 2)
		ft_sb(b, false);
	else if (command_index == 3)
		ft_pa(a, b, false);
	else if (command_index == 4)
		ft_pb(b, a, false);
	else if (command_index == 5)
		ft_ra(a, false);
	else if (command_index == 6)
		ft_rb(b, false);
	else if (command_index == 7)
		ft_rra(a, false);
	else if (command_index == 8)
		ft_rrb(b, false);
	else if (command_index == 9)
		ft_rr(a, b, false);
	else if (command_index == 10)
		ft_rrr(a, b, false);
}
