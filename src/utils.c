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

static char	*join_args(int ac, char **argv)
{
	char	*joined;
	char	*tmp;
	int		i;

	if (ac < 2)
		return (NULL);
	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		tmp = ft_strjoin(joined, " ");
		free(joined);
		if (!tmp)
			return (NULL);
		joined = ft_strjoin(tmp, argv[i++]);
		free(tmp);
		if (!joined)
			return (NULL);
	}
	return (joined);
}

char	**arrayofnumbers(int ac, char **argv)
{
	char	*joined;
	char	**split;

	if (!argv[1] || argv[1][0] == '\0')
		return (NULL);
	if (ac == 2)
		return (ft_split(argv[1], ' '));
	joined = join_args(ac, argv);
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined);
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
