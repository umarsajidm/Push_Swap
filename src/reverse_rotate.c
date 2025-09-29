/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:10:33 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 14:21:43 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_node **stack_a, bool check)
{
	t_node	*temp;
	t_node	*second_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	while (temp->next)
	{
		second_last = temp;
		temp = temp->next;
	}
	second_last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	if (check)
		write(1, "rra\n", 4);
}

void	rrotate_b(t_node **stack_b, bool check)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	second_last = NULL;
	last = *stack_b;
	while (last->next)
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

void	rrotate_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		rrotate_a(stack_a, 0);
	if (stack_b && *stack_b && (*stack_b)->next)
		rrotate_b(stack_b, 0);
	write(1, "rrr\n", 4);
}
