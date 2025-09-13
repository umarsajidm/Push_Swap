/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:07:38 by musajid           #+#    #+#             */
/*   Updated: 2025/09/10 16:07:38 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void addToTheStack(t_node **head, int value);
static t_node *createNewNode(int value);
char **arrayOfNumbers(int ac, char **argv);

int main(int ac, char **av)
{
   int i;
   t_node *stack_a = NULL;

   i = 0;
    if (ac < 2)
        return(0);
    char **num = arrayOfNumbers(ac, av);// also here to validate the numeric value
    while (num[i])
    {
        int number = atoi(num[i]);//can we modify atoi to validate numeric value
        addToTheStack(&stack_a, number);// here to validate if there is double value
        i++;
    }
      // Debug: print list
    t_node *tmp = stack_a;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    
    // if (ac == 2)
    //     free_split(num); // free the ft_split result


    return (0);
}
static t_node *createNewNode(int value)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
        return(NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}

static void addToTheStack(t_node **head, int value)
{
    t_node *new = createNewNode(value);
    t_node *temp;

    if (!new)
        return;
    if (!*head)
    {
        *head = new;
        return;
    }
    temp = *head;
    while (temp->next) //go to the last node
    {
        temp = temp->next;
    }
    temp->next = new; // and link the new node into it.
}

char **arrayOfNumbers(int ac, char **argv)
{
    char **split;

    if (ac == 2) // single string like "10 20 30"
        split = ft_split(argv[1], ' ');
    else // multiple arguments
        split = argv + 1; // skip program name

    return split;
}
