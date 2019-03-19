/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 12:04:52 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/10 12:14:23 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*memory;

	i = 0;
	memory = (char *)malloc(size);
	if (memory == NULL)
		return (NULL);
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return ((void *)memory);
}
