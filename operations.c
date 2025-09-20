#include "push_swap.h"
#include <unistd.h> // for write

// swap top two of stack_a
void swap_a(t_node **stack_a, bool check)
{
    int temp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    temp = (*stack_a)->value;
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->next->value = temp;
    if (check)
        write(1, "sa\n", 3);
}

// swap top two of stack_b
void swap_b(t_node **stack_b, bool check)
{
    int temp;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    temp = (*stack_b)->value;
    (*stack_b)->value = (*stack_b)->next->value;
    (*stack_b)->next->value = temp;
    if (check)
        write(1, "sb\n", 3);
}

// swap both simultaneously
void swap_ab(t_node **stack_a, t_node **stack_b)
{
    if (stack_a && *stack_a && (*stack_a)->next)
        swap_a(stack_a, 0);
    if (!stack_b && *stack_b && (*stack_b)->next)
        swap_b(stack_b, 0);
    write(1, "ss\n", 3);
}
//pushing the first element of stack b and putting on stack a;
void push_a(t_node **stack_a, t_node **stack_b)
{
    t_node *temp;

    if (!stack_b || !*stack_b)
        return ;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;
    write(1, "pa\n", 3);
}
//pushing to b
void push_b(t_node **stack_a, t_node **stack_b)
{
    t_node *temp;

    if (!stack_a || !*stack_a)
        return ;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
    write(1, "pb\n", 3);
}
//rotate a by 1, first elemet becomes last one
void rotate_a(t_node **stack_a, bool check)
{
    t_node *first;
    t_node *temp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ; // nothing to rotate if 0 or 1 element
    first = *stack_a;              // save first element
    *stack_a = (*stack_a)->next;   // move head to 2nd element
    first->next = NULL;            // detach first
    temp = *stack_a;               // go to the last element
    while (temp->next)
        temp = temp->next;
    temp->next = first;            // attach first at the end
    if (check)
        write(1, "ra\n", 3);
}

void rotate_b(t_node **stack_b, bool check)
{
    t_node *first;
    t_node *temp;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ; // nothing to rotate if 0 or 1 element
    first = *stack_b;              // save first element
    *stack_b = (*stack_b)->next;   // move head to 2nd element
    first->next = NULL;            // detach first
    temp = *stack_b;               // go to the last element
    while (temp->next)
        temp = temp->next;
    temp->next = first;            // attach first at the end
    if (check)
        write(1, "rb\n", 3);
}

void rotate_ab(t_node **stack_a, t_node **stack_b)
{
    
    if (!stack_a && *stack_a && (*stack_a)->next)
        rotate_a(stack_a, 0);
    if (!stack_b && *stack_b && (*stack_b)->next)
        rotate_b(stack_b, 0);
    write (1, "rr\n", 3);
}
void rrotate_a(t_node **stack_a, bool check)
{
    t_node *temp;
    t_node *second_last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    temp = *stack_a;
    while(temp->next)
    {
        second_last = temp;
        temp = temp->next;
    }
    second_last->next = NULL; //marking the end of linked list
    temp->next = *stack_a;
    *stack_a = temp;
    if (check)
        write(1, "rra\n", 4);
}

void rrotate_b(t_node **stack_b, bool check)
{
    t_node *last;
    t_node *second_last;

     if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    second_last = NULL;
    last = *stack_b;
    while(last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    if (check)
        write(1, "rrb\n", 4);
}
void rrotate_ab(t_node **stack_a, t_node **stack_b)
{
     if (stack_a && *stack_a && (*stack_a)->next)
        rrotate_a(stack_a, 0);
    if (stack_b && *stack_b && (*stack_b)->next)
        rrotate_b(stack_b, 0);
    write(1, "rrr\n", 4);
}