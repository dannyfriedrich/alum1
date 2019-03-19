/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:03:19 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/10 14:28:21 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int length;

	i = 0;
	length = ft_strlen((char *)s);
	while (i < length + 1)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
