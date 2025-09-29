/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:32:55 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 13:32:55 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> // for INT_MAX

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		swap_a(stack_a, 1);
	else if (a > b && b > c)
	{
		swap_a(stack_a, 1);
		rrotate_a(stack_a, 1);
	}
	else if (a > b && a > c && b < c)
		rotate_a(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else if (a < b && a > c)
		rrotate_a(stack_a, 1);
}

static int	find_minimum(t_node *stack)
{
	int		minimum;

	if (!stack)
		return (INT_MAX);
	minimum = stack->value;
	while (stack)
	{
		if (stack->value < minimum)
			minimum = stack->value;
		stack = stack->next;
	}
	return (minimum);
}

static void	bring_min_top(t_node **stack_a, int value)
{
	t_node	*temp;
	int		i;
	int		len;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	i = 0;
	while (temp && temp->value != value)
	{
		temp = temp->next;
		i++;
	}
	len = size(*stack_a);
	if (i <= len / 2)
		while ((*stack_a)->value != value)
			rotate_a(stack_a, 1);
	else
		while ((*stack_a)->value != value)
			rrotate_a(stack_a, 1);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	count;
	int	minimum;

	if (!stack_a || !*stack_a)
		return ;
	count = size(*stack_a) - 3;
	while (count-- > 0)
	{
		minimum = find_minimum(*stack_a);
		bring_min_top(stack_a, minimum);
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}
