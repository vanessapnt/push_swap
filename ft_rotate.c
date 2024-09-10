#include "push_swap.h"

static	void	ft_rotate(stack_node **head)
{
	if (head && *head && (*head)->next)
	{
		stack_node *first_node = *head;
		stack_node *last_node = find_last_node(*head);
		
		last_node->next = first_node;
		*head = first_node->next;
		(*head)->prev = NULL;
		
		first_node->next = NULL;
		first_node->prev = last_node;
	}
}

static	void	ft_reverse_rotate(stack_node **head)
{
	if (head && *head && (*head)->next)
	{
		stack_node *first_node = *head;
		stack_node *last_node = find_last_node(*head);

		first_node->prev = last_node;
		last_node->prev->next = NULL;
		last_node->next = first_node;
		last_node->prev = NULL;
		*head = last_node;
	}
}

void	ft_ra(stack_node** a){
	ft_rotate(a);
}

void	ft_rb(stack_node** b){
	ft_rotate(b);
}

void	ft_rr(stack_node** a, stack_node** b){
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(stack_node** a){
	ft_reverse_rotate(a);
}

void	ft_rrb(stack_node** b){
	ft_reverse_rotate(b);
}

void	ft_rrr(stack_node** a, stack_node **b){
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}