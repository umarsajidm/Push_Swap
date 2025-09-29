/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:32:49 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 13:32:49 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	if (!temp)
		return (1);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

char	**arrayofnumbers(int ac, char **argv)
{
	char	**split;

	if (ac == 2)
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	return (split);
}

void	freearray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
