/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:32:58 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 13:32:58 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

/* swap two ints */
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* compute how many bits are needed to represent the maximum value */
static int	get_max_bits(t_node *stack)
{
	int		max;
	int		bits;
	t_node	*tmp;

	max = 0;
	bits = 0;
	tmp = stack;
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

static void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b)
		push_a(stack_a, stack_b);
}

static void	process_bit(t_node **stack_a, t_node **stack_b, int bit, int len)
{
	int	j;

	j = 0;
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

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	max_bits;
	int	len;

	i = 0;
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
