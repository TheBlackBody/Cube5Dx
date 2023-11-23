/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:46:01 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/09 20:29:42 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(uintptr_t hexa)
{
	int	len;

	len = 0;
	while (hexa != 0)
	{
		len++;
		hexa = hexa / 16;
	}
	return (len);
}

void	ft_put_hexa(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16);
		ft_put_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_void_hexa(unsigned long int hexa)
{
	int	printlen;

	printlen = 0;
	printlen += write(1, "0x", 2);
	if (hexa == 0)
	{
		printlen += write(1, "0", 1);
	}
	else
	{
		ft_put_hexa(hexa);
		printlen += ft_hexa_len(hexa);
	}
	return (printlen);
}
