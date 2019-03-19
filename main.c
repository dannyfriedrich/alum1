/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 10:05:42 by fblom         #+#    #+#                 */
/*   Updated: 2019/03/16 10:05:42 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			main(int argc, char **argv)
{
	int			fd;
	int			*rows;
	int			*highest;
	char		*string;

	if (argc > 2)
		return (put_errors(1));
	if (argc == 1)
		fd = put_errors(2);
	else
		fd = open(argv[1], O_RDONLY);
	string = get_input(fd);
	rows = (int *)malloc(sizeof(int));
	highest = (int *)malloc(sizeof(int));
	if (string == NULL || error_handling(string, rows, fd) == 1)
		return (put_errors(3));
	if (get_data(string, *rows, highest, fd) == 0 || *rows == 0)
		return (put_errors(3));
	close(fd);
	return (0);
}
