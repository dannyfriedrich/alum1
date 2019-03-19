/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_board.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 15:29:38 by dfreire       #+#    #+#                 */
/*   Updated: 2019/03/16 15:29:38 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		put_chars(int matches, char c)
{
	int i;

	i = 0;
	if (c == '0')
		ft_putstr("\033[1;31m");
	else
		ft_putstr("\033[1;33m");
	while (i < matches)
	{
		ft_putchar(c);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	ft_putstr("\033[0m");
}

static void		put_spaces(int matches, int highest)
{
	while (highest > matches)
	{
		highest--;
		ft_putchar(' ');
	}
}

void			put_board(int *matches, int rows, int highest)
{
	int i;
	int j;

	i = 0;
	while (i < rows)
	{
		if (matches[i] != 0)
		{
			put_spaces(matches[i], highest);
			put_chars(matches[i], '0');
			j = 0;
			while (j < 3)
			{
				put_spaces(matches[i], highest);
				put_chars(matches[i], '|');
				j++;
			}
		}
		if (matches[i] != 0)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
