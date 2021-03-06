/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_sign.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 11:50:59 by fblom         #+#    #+#                 */
/*   Updated: 2019/02/20 11:50:59 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_sign(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	else
		write(1, "+", 1);
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
