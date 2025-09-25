#include "push_swap.h"
#include <limits.h>

static int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi_safe(const char *str, int *out)
{
	long	result;
	int		sign;

	if (!is_number(str))
		return (0);
	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (0);
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}

static int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

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
