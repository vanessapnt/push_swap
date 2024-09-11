/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:42:46 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/11 13:48:55 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

	#include <stdlib.h>
	#include <stdio.h>
	#include <limits.h>

typedef struct t_stack_node{
	int					x;
	struct t_stack_node	*prev;
	struct t_stack_node	*next;
}t_stack_node;

void	ft_sa(t_stack_node **a);
void	ft_sb(t_stack_node **b);
void	ft_ss(t_stack_node **a, t_stack_node **b);

void	ft_pa(t_stack_node **a, t_stack_node **b);
void	ft_pb(t_stack_node **b, t_stack_node **a);

void	ft_ra(t_stack_node **a);
void	ft_rb(t_stack_node **b);
void	ft_rr(t_stack_node **a, t_stack_node **b);

void	ft_rra(t_stack_node **a);
void	ft_rrb(t_stack_node **b);
void	ft_rrr(t_stack_node **a, t_stack_node **b);

void	ft_tiny_sort(t_stack_node **a);

//mettre tout ca en static et a la place sa, sb, ss...
void	ft_print_stack(t_stack_node *a);
int		ft_stack_length(t_stack_node *head);
t_stack_node	*find_max_node(t_stack_node *head);
t_stack_node	*find_min_node(t_stack_node *head);
t_stack_node	*find_last_node(t_stack_node *head);
char	**ft_split(char *s, char c);

// void	ft_swap(t_stack_node **head);
// void	ft_push(t_stack_node **dest, t_stack_node **src);
// void	ft_rotate(t_stack_node **head);
// void	ft_reverse_rotate(t_stack_node **head);
#endif