#include "push_swap.h"

static void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static void sortarray(int *array, int sizee)
{
    int i;
    int j;

    i = 0;
    while (i < sizee - 1)
    {
        j = 0;
        while(j < sizee - 1 - i)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
            j++;
        }
        i++;
    }
}
static int getting_index(int *array, int sizee, int value)
{
    int i;

    i = 0;
    while(i < sizee)
    {
        if (array[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

void indexing_stack(t_node *stack)
{
    int     *array;
    int     i;
    t_node *temp;
    int     sizeofstack;

    sizeofstack = size(stack);
    array = malloc(sizeof(int) * sizeofstack);
    temp = stack;
    i = 0;
    while(temp)
    {
        array[i++] = temp->value;
        temp = temp->next;
    }
    sortarray(array, sizeofstack);
    temp = stack;
    while(temp)
    {
        temp->value = getting_index(array, sizeofstack, temp->value);
        temp = temp->next;
    }
    free(array);
}

static int get_max_bits(t_node *stack)
{
    int max;
    int bits;
    t_node *temp;

    max = 0;
    bits = 0;
    temp = stack;
    while(temp)
    {
        if (temp->value > max)
            max = temp->value;
        temp = temp->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

void radix_sort(t_node **stack_a, t_node **stack_b)
{
    int i;
    int j;
    int sizeofa;
    int max_bit;
    
    sizeofa = size(*stack_a);
    max_bit = get_max_bits(*stack_a);
    i = 0;
    while (i < max_bit)
    {
        j = 0;
        while(j < sizeofa)
        {
            if((((*stack_a)->value >> i) & 1) == 0)
                push_b(stack_a, stack_b);
            else
                rotate_a(stack_a, 1);
            j++;
        }
        i++;
    }
    while(*stack_b)
        push_a(stack_a, stack_b);
}
