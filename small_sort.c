#include "push_swap.h"

void sort_three(t_node **stack_a)
{
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && b < c && a < c)             // case: 2 1 3 → sa
        swap_a(stack_a, 1);
    else if (a > b && b > c)                 // case: 3 2 1 → sa + rra
    {
        swap_a(stack_a, 1);
        rrotate_a(stack_a, 1);
    }
    else if (a > b && b < c && a > c)        // case: 3 1 2 → ra
        rotate_a(stack_a, 1);
    else if (a < b && b > c && a < c)        // case: 1 3 2 → sa + ra
    {
        swap_a(stack_a, 1);
        rotate_a(stack_a, 1);
    }
    else if (a < b && b > c && a > c)        // case: 2 3 1 → rra
        rrotate_a(stack_a, 1);
}
static int  find_the_minimum(t_node *stack_a)
{
    t_node *temp;
    int minimum;

    if (!stack_a)
        return (0);
    temp = stack_a;
    minimum = temp->value;
    while (temp)
    {
        if (temp->value < minimum)
            minimum = temp->value;
        temp = temp->next;
    }
    return (minimum);
}

static void bring_min_top(t_node **stack_a, int value)
{
    t_node *temp;
    int i;
    int j;

    if (!stack_a)
        return ;
    temp = *stack_a;
    i = 0;
    while (temp && temp->value != value)
    {
        temp = temp->next;
        i++;
    }
    j = size(stack_a);
    if (i < j/2)
        while ((*stack_a)->value != value)
            rotate_a(stack_a, 1);
    while((*stack_a)->value != value)
        rrotate_a(stack_a, 1);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    int first;
    int second;

    first = find_the_minimum(stack_a);
    bring_min_top(stack_a, first);
    push_b(stack_a, stack_b);
    second = find_the_minimum(stack_a);
    bring_min_top(stack_a, second);
    push_b(stack_a, stack_b);
    sort_three(stack_a);
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);    
}
