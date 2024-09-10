#include "push_swap.h"

stack_node  *find_max_node(stack_node* head)
{
    stack_node *curr = head;
    stack_node *max = curr;
    while(curr)
    {
        if(curr->x > max->x)
            max = curr;
        curr = curr->next;
    }
    return (max);
}

stack_node  *find_min_node(stack_node *head)
{
    stack_node *curr = head;
    stack_node *min = curr;

    while(curr)
    {
        if(curr->x < min->x)
            min = curr;
        curr = curr->next;
    }
    return(min);
}

int ft_stack_length(stack_node *head)
{
    int len = 0;
    stack_node *curr = head;

    while(curr)
    {
        curr = curr->next;
        len++;
    }
    return(len);
}

stack_node	*find_last_node(stack_node *head)
{
	stack_node *curr = head;
	if(curr)
	{
		while(curr->next)
			curr = curr->next;
	}
	return (curr);
}

void    ft_print_stack(stack_node *a)
{
    stack_node *curr = a;
    while(curr != NULL)
    {
        printf("%d\n", curr->x);
        curr = curr->next;
    }
}
