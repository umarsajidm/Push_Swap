/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:08:51 by musajid           #+#    #+#             */
/*   Updated: 2025/09/29 14:21:37 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a, bool check)
{
	int	temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
	if (check)
		write(1, "sa\n", 3);
}

void	swap_b(t_node **stack_b, bool check)
{
	int	temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
	if (check)
		write(1, "sb\n", 3);
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		swap_a(stack_a, 0);
	if (!stack_b && *stack_b && (*stack_b)->next)
		swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}
