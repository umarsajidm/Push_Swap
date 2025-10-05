/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:04 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 13:33:04 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_dispatcher(t_node **a, t_node **b)
{
	int	n;

	n = size(*a);
	if (n == 2)
		swap_a(a, 1);
	else if (n == 3)
		sort_three(a);
	else if (n <= 5)
		sort_five(a, b);
	else
	{
		indexing_stack(*a);
		radix_sort(a, b);
	}
}

static void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*next;

	if (!stack)
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**num;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	num = arrayofnumbers(ac, av);
	if (!num || !fill_stack(&stack_a, num))
	{
		if (num)
			freearray(num);
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!sorted(&stack_a))
		sort_dispatcher(&stack_a, &stack_b);
	freearray(num);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
