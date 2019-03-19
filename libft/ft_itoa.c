/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 19:40:07 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/16 19:40:08 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_minint(void)
{
	char *min;

	min = (char *)malloc(sizeof(char) * 11 + 1);
	if (min == NULL)
		return (min);
	min = ft_strcpy(min, "-2147483648");
	return (min);
}

static char		*ft_makestring(int digits, int n, char *str)
{
	int i;

	i = 0;
	while (i < digits)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		isneg;

	if (n == -2147483648)
		return (ft_minint());
	isneg = 0;
	digits = ft_getdigits(n);
	if (n < 0)
		isneg = 1;
	str = (char *)malloc(sizeof(char) * (digits + isneg) + 1);
	if (str == NULL)
		return (str);
	str[digits + isneg] = '\0';
	if (n < 0)
	{
		str[digits] = '-';
		n *= -1;
	}
	str = ft_makestring(digits, n, str);
	return (ft_reverse_string(str));
}
