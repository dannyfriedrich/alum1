/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 11:32:39 by fblom         #+#    #+#                 */
/*   Updated: 2019/03/16 11:32:40 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			put_errors(int error)
{
	if (error == 1)
		ft_writeincolours("usage: ./alum1 input_file\n", "light yellow");
	if (error == 2)
	{
		start_game();
		ft_writeincolours("Enter the amount of matches per row and hit double \
enter to submit:\n", "light yellow");
		ft_putstr_fd("\033[93m", 0);
	}
	if (error == 3)
		ft_putstr_fd("ERROR\n", 2);
	return (0);
}

int			error_handling(char *string, int *rows, int fd)
{
	int i;

	i = 0;
	*rows = 0;
	while (string[i] != '\0')
	{
		if (ft_isdigit(string[i]) != 1 && string[i] != '\n')
			return (1);
		if (string[i] == '\n')
			*rows += 1;
		i++;
	}
	if (fd == 0)
		*rows -= 1;
	return (0);
}
