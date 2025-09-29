/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:08 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 13:33:08 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a, bool check)
{
	t_node	*first;
	t_node	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	first->next = NULL;
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	if (check)
		write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack_b, bool check)
{
	t_node	*first;
	t_node	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	first->next = NULL;
	temp = *stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	if (check)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a && *stack_a && (*stack_a)->next)
		rotate_a(stack_a, 0);
	if (!stack_b && *stack_b && (*stack_b)->next)
		rotate_b(stack_b, 0);
	write (1, "rr\n", 3);
}
