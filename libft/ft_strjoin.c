/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:55:13 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/16 10:55:16 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	j;
	char	*new_string;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * total_len + 1);
	if (new_string == NULL)
		return (new_string);
	new_string[total_len] = '\0';
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new_string[j] = s1[i];
		i++;
		j++;
	}
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		new_string[j] = s2[i - ft_strlen(s1)];
		i++;
		j++;
	}
	return (new_string);
}
