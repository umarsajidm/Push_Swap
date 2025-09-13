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

typedef struct s_node
{
    int value;
    struct s_node *next;
}              t_node;



size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char			**ft_split(const char *str, char del);
void	*ft_calloc(size_t nmemb, size_t size);
char **arrayOfNumbers(int ac, char **argv);

#endif

