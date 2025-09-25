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

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**num;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	num = arrayOfNumbers(ac, av);
	if (!fill_stack(&stack_a, num))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!sorted(&stack_a))
		sort_dispatcher(&stack_a, &stack_b);
	if (ac == 2)
		freearray(num);
	return (0);
}
