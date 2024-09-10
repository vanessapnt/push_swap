#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct stack_node{
    int x;
    struct stack_node *prev;
    struct stack_node *next;
}stack_node;

void    ft_sa(stack_node **a);
void    ft_sb(stack_node **b);
void    ft_ss(stack_node **a, stack_node **b);

void    ft_pa(stack_node **a, stack_node **b);
void    ft_pb(stack_node **b, stack_node **a);

void	ft_ra(stack_node** a);
void	ft_rb(stack_node** b);
void	ft_rr(stack_node** a, stack_node** b);

void	ft_rra(stack_node** a);
void	ft_rrb(stack_node** b);
void	ft_rrr(stack_node** a, stack_node** b);

void    ft_tiny_sort(stack_node **a);

//mettre tout ca en static et a la place sa, sb, ss...
void        ft_print_stack(stack_node *a);
int         ft_stack_length(stack_node *head);
stack_node  *find_max_node(stack_node* head);
stack_node  *find_min_node(stack_node *head);
stack_node	*find_last_node(stack_node *head);
char        **ft_split(char *s, char c);

// void    ft_swap(stack_node **head);
// void    ft_push(stack_node **dest, stack_node **src);
// void    ft_rotate(stack_node **head);
// void	ft_reverse_rotate(stack_node **head);
#endif