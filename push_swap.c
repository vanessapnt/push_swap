#include "push_swap.h"

int main(int argc, char **argv)
{
	stack_node *a;
	stack_node *b;
	char **split_result;

	a = NULL;
	b = NULL;
	if(argc == 1 || argc == 2 && !argv[1][0]) //no arg || ""
		return(1);
	else if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		if (!split_result)
			init_stack_a(&a, split_result);
		while (*split_result++)
			free(split_result);
		free(split_result);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_length(a) == 2)
			sa(&a);
		else if (ft_stack_length(a) == 3)
			ft_tiny_sort(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return(0);
}

void	ft_free_stack(stack_node	**head)
{
	stack_node *curr;

	if(*head == NULL)
		return;
	curr = *head;
	while(curr->next)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*head = NULL;
}

void	free_errors(stack_node **a)
{
	ft_free_stack(a);
	printf("Error\n");
	exit(1);
}

int	error_syntax(char *s)
{
	//first char must be '-', '+' or digit
	if (!(*s == '-' || *s == '+' || (*s >= '0' && *s <= '9')))
		return(1);
	//second char must be digit
	if ((*s == '-' || *s == '+') && !(s[1] >= '0' && s[1] <= '9'))
		return(1);
	//only digits following
	while(++*s)
	{
		if(!(s[1] >= '0' && s[1] <= '9'))
			return(1);
	}
	return(0);
}

int	error_double(stack_node *a, int	nb)
{

}

void	add_node(stack_node **a, int nb)
{

}

int	stack_sorted(stack_node **a)
{

}

void	init_stack_a(stack_node **a, char **argv)
{
	int	i;
	long	nb;

	i = 0;
	while(argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors(a);
		if (error_double(*a, (int)nb))
			free_errors(a);
		add_node(a, (int)nb);
		i++;
	}
}
