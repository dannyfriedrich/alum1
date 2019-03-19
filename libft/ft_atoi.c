/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:23:03 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/14 16:23:05 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_returner(unsigned long result, int is_negative)
{
	if (result > 9223372036854775807 && is_negative == -1)
		return (0);
	if (result >= 9223372036854775807)
		return (-1);
	return (result * is_negative);
}

int				ft_atoi(const char *str)
{
	int				i;
	int				is_negative;
	unsigned long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_negative = -1;
	else if (str[i] == '+')
		is_negative = 1;
	else
	{
		is_negative = 1;
		i--;
	}
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return ((int)ft_atoi_returner(result, is_negative));
}
