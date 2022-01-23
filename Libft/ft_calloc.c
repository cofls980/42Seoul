/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:27:45 by chaekim           #+#    #+#             */
/*   Updated: 2021/06/10 14:43:02 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	if (!(arr = (unsigned char *)malloc(size * nmemb)))
		return (0);
	i = 0;
	while (i < size * nmemb)
		arr[i++] = 0;
	return (arr);
}
