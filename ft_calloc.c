/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: INTRA_LOGIN <INTRA_LOGIN@student.hive.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:19:57 by INTRA_LOGIN       #+#    #+#             */
/*   Updated: 2025/05/13 21:08:21 by INTRA_LOGIN      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	temp = (unsigned char *)malloc(nmemb * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		temp[i++] = 0;
	return ((void *)temp);
}