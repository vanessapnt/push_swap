/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:02:26 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/21 16:57:15 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void init_commands(char **commands)
{
	commands[0] = "sa\n";
	commands[1] = "sss\n";
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

int ft_strcmp(char **commands, char *str)
{
	char *curr_commands;
	char *curr_str;
	while(*commands)
	{
		curr_commands = *commands;
		curr_str = str;
		while(curr_str && curr_commands && *curr_str == *curr_commands)
		{
			curr_commands++;
			curr_str++;
		}
		if (*curr_str == '\0' && *curr_commands == '\0')
			return(1);
		commands++;
	}
	return(0);
}

void	error_syntax(char **str)
{
	char	*commands[11];

	init_commands(commands);

	while(*str)
	{
		if (!(ft_strcmp(commands, *str)))
			printf("Error\n");
		str++;
	}
}

int	main(int argc, char **argv)
{

	error_syntax();
}