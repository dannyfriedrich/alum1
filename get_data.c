/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 12:03:32 by fblom         #+#    #+#                 */
/*   Updated: 2019/03/16 12:03:32 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int				get_data(char *string, int rows, int *highest, int fd)
{
	int		*matches;
	int		i;

	matches = (int *)malloc(sizeof(int) * rows);
	i = 0;
	while (i < rows)
	{
		matches[i] = ft_atoi(string);
		if (i == 0 && matches[i] == 0)
			return (0);
		if (matches[i] > *highest)
			*highest = matches[i];
		if (matches[i] > 10000 || matches[i] < 1)
			return (0);
		string = ft_strchr(string + 1, '\n');
		i++;
	}
	if (rows == 0)
		return (0);
	if (fd != 0)
		start_game();
	play_game(matches, rows, *highest);
	return (1);
}

char			*get_input(int fd)
{
	char		buf[BUFF_SIZE + 1];
	char		*string;
	char		*temp;
	int			ret;

	if (fd == -1)
		return (NULL);
	ret = 1;
	string = ft_strdup("\0");
	while (buf[0] != '\n' && ret != 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		temp = ft_strjoin(string, buf);
		free(string);
		string = temp;
	}
	return (string);
}
