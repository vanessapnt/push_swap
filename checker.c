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
	commands[0] = "sa";
	commands[1] = "sss";
	commands[2] = "sb";
	commands[3] = "pa";
	commands[4] = "pb";
	commands[5] = "ra";
	commands[6] = "rb";
	commands[7] = "rra";
	commands[8] = "rrb";
	commands[9] = "rr";
	commands[10] = "rrr";
}

void	error_syntax(char **str)
{
	char	*commands[11];

	init_commands(commands);

	while(*str)
	{
		if (!(ft_strcmp(*commands, *str)))
			printf("Error\n");

	}
}

int	main(int argc, char **argv)
{
	error_syntax(argv);
}

int ft_strcmp(char **commands, char *str)
{
	while(*commands)
	{
		
	}
}