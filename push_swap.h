/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musajid <musajid@hive.student.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:08:19 by musajid           #+#    #+#             */
/*   Updated: 2025/09/10 16:08:19 by musajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
}              t_node;

//operations

//swap
void swap_a(t_node **stack_a, bool check);
void swap_b(t_node **stack_b, bool check);
void swap_ab(t_node **stack_a, t_node **stack_b);
//push
void push_a(t_node **stack_a, t_node **stack_b);
void push_b(t_node **stack_a, t_node **stack_b);
//rotate
void rotate_a(t_node **stack_a, bool check);
void rotate_b(t_node **stack_b, bool check);
void rotate_ab(t_node **stack_a, t_node **stack_b);
//reverse_rotate
void rrotate_a(t_node **stack_a, bool check);
void rrotate_b(t_node **stack_b, bool check);
void rrotate_ab(t_node **stack_a, t_node **stack_b);
//small sort
void sort_three(t_node **stack_a);
void sort_five(t_node **stack_a, t_node **stack_b);
//radix_sort
void radix_sort(t_node **stack_a, t_node **stack_b);
void indexing_stack(t_node *stack);

//utils
void	freearray(char **arr);
char	**arrayOfNumbers(int ac, char **argv);
int	sorted(t_node **stack_a);
int	size(t_node *stack);
//parsing
int	fill_stack(t_node **stack, char **num);


size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char			**ft_split(const char *str, char del);
void	*ft_calloc(size_t nmemb, size_t size);
char **arrayOfNumbers(int ac, char **argv);
int	ft_atoi(const char *str);
int	ft_isdigit(int a);
int size(t_node *stack_a);

#endif

