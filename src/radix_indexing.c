/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:46 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 14:18:07 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* simple bubble sort for the temporary */
static void	sortarray(int *array, int len)
{
	int	i;
	int	j;

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
static int	getting_index(int *array, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	*stack_to_array(t_node *stack, int len)
{
	int	*array;
	int	i;

	i = 0;
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

static void	replace_with_index(t_node *stack, int *array, int len)
{
	while (stack)
	{
		stack->value = getting_index(array, len, stack->value);
		stack = stack->next;
	}
}

void	indexing_stack(t_node *stack)
{
	int	*array;
	int	len;

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
