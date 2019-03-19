/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getdigits.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 09:35:44 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/21 09:35:45 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getdigits(int n)
{
	int		digits;

	if (n < 0)
		n *= -1;
	digits = 1;
	while (n / 10 > 0)
	{
		digits += 1;
		n = n / 10;
	}
	return (digits);
}
