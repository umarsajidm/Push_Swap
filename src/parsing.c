/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:06 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 13:33:06 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

static int	add_to_stack(t_node **head, int value)
{
	t_node	*new;
	t_node	*temp;

	if (has_duplicate(*head, value))
		return (0);
	new = create_node(value);
	if (!new)
		return (0);
	if (!*head)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

int	fill_stack(t_node **stack, char **num)
{
	int	i;
	int	val;

	i = 0;
	while (num[i])
	{
		if (!ft_atoi_safe(num[i], &val))
			return (0);
		if (!add_to_stack(stack, val))
			return (0);
		i++;
	}
	return (1);
}
