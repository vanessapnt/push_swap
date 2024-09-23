/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:42:46 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/23 14:00:35 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack_node
{
	int					x;
	struct t_stack_node	*prev;
	struct t_stack_node	*next;
	int					index;
	bool				above_median;
	struct t_stack_node	*target;
	int					push_cost;
}						t_stack_node;

// Commands
void					ft_sa(t_stack_node **a, bool print);
void					ft_sb(t_stack_node **b, bool print);
void					ft_ss(t_stack_node **a, t_stack_node **b, bool print);
void					ft_pa(t_stack_node **a, t_stack_node **b, bool print);
void					ft_pb(t_stack_node **b, t_stack_node **a, bool print);
void					ft_ra(t_stack_node **a, bool print);
void					ft_rb(t_stack_node **b, bool print);
void					ft_rr(t_stack_node **a, t_stack_node **b, bool print);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					ft_rra(t_stack_node **a, bool print);
void					ft_rrb(t_stack_node **b, bool print);
void					ft_rrr(t_stack_node **a, t_stack_node **b, bool print);
void					reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

// Push_Swap structure
char					**ft_split(char *s, char c);
void					init_stack_a(t_stack_node **a, char **argv);
int						stack_sorted(t_stack_node *a);
int						ft_stack_length(t_stack_node *head);
void					ft_tiny_sort(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
// void free_stack(t_stack_node **a);

// Tool Box
t_stack_node			*find_max_node(t_stack_node *head);
t_stack_node			*find_min_node(t_stack_node *head);
t_stack_node			*find_last_node(t_stack_node *head);
int						ft_stack_length(t_stack_node *head);
void					ft_print_stack(t_stack_node *a);

int						stack_sorted(t_stack_node *a);
void					ft_free_stack(t_stack_node **head);
void					add_node(t_stack_node **a, int nb);
void					min_on_top(t_stack_node **a);
void					prep_for_push(t_stack_node **head,
							t_stack_node *cheapest_node, char stack_name);

// Set members of the nodes
t_stack_node			*find_cheapest(t_stack_node *a);
void					set_target_a(t_stack_node *a, t_stack_node *b);
void					set_target_b(t_stack_node *a, t_stack_node *b);
void					set_position(t_stack_node *head);
void					set_cost(t_stack_node *a, t_stack_node *b);

// Sort stacks
void					init_members_a(t_stack_node *a, t_stack_node *b);
void					init_members_b(t_stack_node *a, t_stack_node *b);
void					push_a_to_b(t_stack_node **a, t_stack_node **b);
void					push_b_to_a(t_stack_node **a, t_stack_node **b);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
#endif