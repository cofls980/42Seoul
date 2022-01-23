/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:31:28 by chaekim           #+#    #+#             */
/*   Updated: 2021/06/10 14:31:29 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(int n, int fd)
{
	if (n <= -10 || n >= 10)
		ft_print(n / 10, fd);
	n %= 10;
	ft_putchar_fd('0' + (n < 0 ? -n : n), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_print(n, fd);
}
