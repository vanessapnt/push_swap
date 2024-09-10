
#include "push_swap.h"

static  void    ft_push(stack_node **dest, stack_node **src)
{
    if (dest && src && (*src))
    {
        stack_node *top_dest = *dest;
        stack_node *top_src = *src;

        if (top_src->next)
            top_src->next->prev = NULL;
        *src = top_src->next;
        top_src->next = top_dest;
        if (top_dest)
            top_dest->prev = top_src;

        *dest = top_src;
    }
}
void    ft_pa(stack_node **a, stack_node **b)
{
    ft_push(a, b);
}

void    ft_pb(stack_node **b, stack_node **a)
{
    ft_push(b, a);
}