#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

/* swap two ints */
static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* simple bubble sort for the temporary array */
static void sortarray(int *array, int len)
{
    int i;
    int j;

    i = 0;
    while (i < len - 1)
    {
        j = 0;
        while (j < len - 1 - i)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
            j++;
        }
        i++;
    }
}

/* return index of value in array (0..len-1) */
static int getting_index(int *array, int len, int value)
{
    int i = 0;

    while (i < len)
    {
        if (array[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

// /* create sorted array of values and replace node->value with rank (0..n-1) */
// void indexing_stack(t_node *stack)
// {
//     int     *array;
//     int     i;
//     t_node  *tmp;
//     int     len;

//     if (!stack)
//         return;
//     len = size(stack);
//     array = malloc(sizeof(int) * len);
//     if (!array)
//         return;
//     tmp = stack;
//     i = 0;
//     while (tmp)
//     {
//         array[i++] = tmp->value;
//         tmp = tmp->next;
//     }
//     sortarray(array, len);
//     tmp = stack;
//     while (tmp)
//     {
//         tmp->value = getting_index(array, len, tmp->value);
//         tmp = tmp->next;
//     }
//     free(array);
// }

static int *stack_to_array(t_node *stack, int len)
{
    int *array;
    int i = 0;

    array = malloc(sizeof(int) * len);
    if (!array)
        return (NULL);
    while (stack)
    {
        array[i++] = stack->value;
        stack = stack->next;
    }
    return (array);
}

static void replace_with_index(t_node *stack, int *array, int len)
{
    while (stack)
    {
        stack->value = getting_index(array, len, stack->value);
        stack = stack->next;
    }
}

void indexing_stack(t_node *stack)
{
    int     *array;
    int     len;

    if (!stack)
        return ;
    len = size(stack);
    array = stack_to_array(stack, len);
    if (!array)
        return ;
    sortarray(array, len);
    replace_with_index(stack, array, len);
    free(array);
}

/* compute how many bits are needed to represent the maximum value */
static int get_max_bits(t_node *stack)
{
    int max = 0;
    int bits = 0;
    t_node *tmp = stack;

    while (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

/* radix sort using stack_b as temporary storage
   * Precondition: stack_a values are ranks 0..n-1 (use indexing_stack before calling).
*/
/* original number of elements */
/* iterate at most 'len' times for this bit.
check *stack_a before deref to avoid segfault if stack_a becomes empty. */
/* if stack_a is empty, nothing to check; just continue iterating */
 /* after finishing this bit, move everything back to a */

// void radix_sort(t_node **stack_a, t_node **stack_b)
// {
//     int i;
//     int j;
//     int len;
//     int max_bits;

//     if (!stack_a || !*stack_a)
//         return;
//     len = size(*stack_a);
//     max_bits = get_max_bits(*stack_a);
//     i = 0;
//     while (i < max_bits)
//     {
//         j = 0;
//         while (j < len)
//         {
//             if (!*stack_a)
//             {
//                 j++;
//                 continue;
//             }
//             if ((((*stack_a)->value >> i) & 1) == 0)
//                 push_b(stack_a, stack_b);
//             else
//                 rotate_a(stack_a, 1);
//             j++;
//         }
//         while (*stack_b)
//             push_a(stack_a, stack_b);
//         i++;
//     }
// }

static void push_back_to_a(t_node **stack_a, t_node **stack_b)
{
    while (*stack_b)
        push_a(stack_a, stack_b);
}

static void process_bit(t_node **stack_a, t_node **stack_b, int bit, int len)
{
    int j = 0;

    while (j < len)
    {
        if ((((*stack_a)->value >> bit) & 1) == 0)
            push_b(stack_a, stack_b);
        else
            rotate_a(stack_a, 1);
        j++;
    }
    push_back_to_a(stack_a, stack_b);
}

void radix_sort(t_node **stack_a, t_node **stack_b)
{
    int i = 0;
    int max_bits;
    int len;

    if (!stack_a || !*stack_a)
        return ;
    len = size(*stack_a);
    max_bits = get_max_bits(*stack_a);
    while (i < max_bits)
    {
        process_bit(stack_a, stack_b, i, len);
        i++;
    }
}
