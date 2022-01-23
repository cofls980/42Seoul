/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:30:46 by chaekim           #+#    #+#             */
/*   Updated: 2021/06/10 14:36:51 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_tmp = (unsigned char*)dest;
	src_tmp = (const unsigned char*)src;
	while (i < len)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
