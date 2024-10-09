/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:53:36 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 14:21:02 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../getnextline/get_next_line.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

void	init_commands(char **commands);
int		ft_strcmp(char **commands, char *str);
void	execute_command(int command_index, t_stack_node **a, t_stack_node **b);

#endif