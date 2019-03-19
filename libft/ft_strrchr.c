/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:45:16 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/10 14:57:16 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int length;

	i = 0;
	length = ft_strlen((char *)s);
	while (i < length)
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}
