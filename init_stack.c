#include "push_swap.h"

int main(){

	t_stack_node *first = malloc(sizeof(t_stack_node));
	if (first == NULL)
		return(1);
	t_stack_node *second = malloc(sizeof(t_stack_node));
	if (second == NULL)
		return(1);
	t_stack_node *third = malloc(sizeof(t_stack_node));
	if (third == NULL)
		return(1);
	t_stack_node *a = first;

	first->x = 1;
	first->prev = NULL;
	first->next = second;

	second->x = 3;
	second->prev = first;
	second->next = third;

	third->x = 2;
	third->prev = second;
	third->next = NULL;

	t_stack_node *fourth = malloc(sizeof(t_stack_node));
	if (fourth == NULL)
		return(1);
	t_stack_node *fifth = malloc(sizeof(t_stack_node));
	if (fifth == NULL)
		return(1);
	t_stack_node *sixth = malloc(sizeof(t_stack_node));
	if (sixth == NULL)
		return(1);
	t_stack_node *b = fourth;

	fourth->x = 4;
	fourth->prev = NULL;
	fourth->next =fifth;

	fifth->x = 5;
	fifth->prev = fourth;
	fifth->next = sixth;

	sixth->x = 6;
	sixth->prev =fifth;
	sixth->next = NULL;

	printf("stack a :\n");
	ft_print_stack(a);
	printf("stack b :\n");
	ft_print_stack(b);

	//ft_rrr(&a, &b);

	printf("new stack a :\n");
	ft_print_stack(a);
	printf("stack b :\n");
	ft_print_stack(b);

	printf("length of stack is %d\n", ft_stack_length(a));

	printf("min of stack a is :%d\n", ((find_min_node(a))->x));
	printf("max of stack a is :%d\n", ((find_max_node(a))->x));

	//printf("last node of stack b is :%d\n", ((find_last_node(b))->x));

//pas ouber de free avec une fonction
	return(0);
}

