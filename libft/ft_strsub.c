/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:44:19 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/16 10:44:19 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*string;

	if (s == NULL)
		return (NULL);
	string = (char *)malloc(sizeof(char) * len + 1);
	if (string == NULL)
		return (string);
	string[len] = '\0';
	i = 0;
	while (i < len)
	{
		string[i] = s[i + start];
		i++;
	}
	return (string);
}
