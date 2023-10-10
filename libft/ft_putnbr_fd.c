/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:02:46 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/19 15:36:01 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void                ft_putnbr_fd(int n, int fd) 
{ 
	if (n == -2147483648) 
		ft_putstr_fd("-2147483648", fd); 
	else if (n < 0) 
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
