/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substringsize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 09:29:24 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/21 09:29:24 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_substring_size(const char *s, char c)
{
	size_t len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}
