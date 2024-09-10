#include "push_swap.h"

static	void	ft_swap(stack_node **head)
{
	if(head != NULL && *head != NULL && (*head)->next != NULL)
	{
		stack_node *node1 = (*head);
		stack_node *node2 = (*head)->next;

		node1->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = node1;

		node1->prev = node2;
		node2->prev = NULL;
		node2->next = node1;

		*head = node2;
	}
}

void	ft_sa(stack_node **a){
	ft_swap(a);
}

void	ft_sb(stack_node **b){
	ft_swap(b);
}

void	ft_ss(stack_node **a, stack_node **b){
	ft_swap(a);
	ft_swap(b);
}