#include "push_swap.h"

int main(int argc, char **argv)
{
    stack_node *a;
    stack_node *b;

    a = NULL;
    b = NULL;
    if(argc == 1 || argc == 2 && !argv[1][0]) //no arg || ""
        return(1);
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
        //arr[], separateur -> arr[][]
    init_stack_a(&a, argv + 1); //check errors

}