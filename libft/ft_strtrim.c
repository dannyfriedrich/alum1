/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:03:44 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/16 11:03:44 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*make_trim(int i, int trim_size, int white_start, const char *s)
{
	char	*trim;

	trim = (void *)malloc(sizeof(char) * trim_size + 1);
	if (trim == NULL)
		return (NULL);
	trim[trim_size] = '\0';
	while (i < trim_size)
	{
		trim[i] = s[i + white_start];
		i++;
	}
	return (trim);
}

static int		return_i(const char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	white_start;
	size_t	white_end;
	size_t	trim_size;
	char	*trim;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return ("");
	white_start = i;
	i = ft_strlen(s) - 1;
	i = return_i(s, i);
	i++;
	white_end = ft_strlen(s) - i;
	trim_size = ft_strlen(s) - white_start - white_end;
	i = 0;
	trim = make_trim(i, trim_size, white_start, s);
	if (trim == NULL)
		return (trim);
	return (trim);
}
