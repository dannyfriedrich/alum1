/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:22:45 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/15 16:22:45 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		define_i(int *save, int i)
{
	if (*save != 0)
	{
		i = *save;
		*save = 0;
		return (i);
	}
	else
		return (i + 1);
}

char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		*save;

	i = 0;
	j = 0;
	save = (int *)malloc(sizeof(int) * 1);
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		*save = 0;
		if (haystack[i] == needle[j])
			*save = i + 1;
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i - ft_strlen(needle));
		}
		i = define_i(save, i);
		j = 0;
	}
	return (NULL);
}
