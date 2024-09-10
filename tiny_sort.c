#include "push_swap.h"

void    ft_tiny_sort(stack_node **a)
{
    stack_node *max = find_max_node(*a);

    if (*a == max)
        ft_ra(a);
    else if ((*a)->next == max)
        ft_rra(a);
    if ((*a)->x > (*a)->next->x)
        ft_sa(a);
}
