/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 20:10:47 by fblom         #+#    #+#                 */
/*   Updated: 2019/03/16 20:10:47 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int					switchturn(int turn)
{
	if (turn == 1)
		return (0);
	return (1);
}

static int					player_turn(int *matches, int i)
{
	char		*buf;

	ft_writeincolours("Lucifer asks: how many matches will you take?\
		\n\n", "light yellow");
	ft_putchar('\n');
	buf = NULL;
	while ((!buf || ft_atoi(buf) > matches[i] ||
		ft_atoi(buf) > 3 || ft_atoi(buf) < 1))
	{
		ft_putstr_fd("\033[93m", 0);
		get_next_line(0, &buf);
		ft_putstr("\n\n");
		if ((ft_atoi(buf) > matches[i] || ft_atoi(buf) > 3 || ft_atoi(buf) < 1))
			ft_writeincolours("Very funny...\n\n\n", "red");
		free(buf);
	}
	matches[i] -= ft_atoi(buf);
	if (matches[i] == 0 && i == 0)
		return (-2);
	return (0);
}

static int					lucifer_turn(int *matches, int i)
{
	if ((matches[i] == 2 || matches[i] == 3 || matches[i] == 4) && i == 0)
		matches[i] = lucifer_takes(matches[i], matches[i] - 1);
	else if ((matches[i] - 4) % 4 == 0 && matches[i] - 3 > 0 && i == 0)
		matches[i] = lucifer_takes(matches[i], 3);
	else if ((matches[i] - 3) % 4 == 0 && matches[i] - 2 > 0 && i == 0)
		matches[i] = lucifer_takes(matches[i], 2);
	else if ((matches[i] - 2) % 4 == 0 && matches[i] - 1 > 0 && i == 0)
		matches[i] = lucifer_takes(matches[i], 1);
	else if (matches[i] >= 1 && matches[i] <= 3 && i != 0 &&
		((matches[i - 1] - 1) % 4 == 0 || matches[i - 1] < 5))
		matches[i] = lucifer_takes(matches[i], matches[i]);
	else
		matches[i] = lucifer_takes(matches[i], 1);
	ft_putstr("\n\n");
	if (matches[i] == 0 && i == 0)
		return (-3);
	return (1);
}

static int					prompt_for_start(int first)
{
	char	*buf;
	char	c;

	if (first == -3)
	{
		ft_writeincolours("Now, who starts the game?\n", "light yellow");
		ft_writeincolours("L ", "red");
		ft_writeincolours("for Lucifer, ", "light yellow");
		ft_writeincolours("M ", "red");
		ft_writeincolours("for you\n\n", "light yellow");
	}
	ft_putstr_fd("\033[93m", 0);
	get_next_line(0, &buf);
	c = buf[0];
	free(buf);
	if (c != 'M' && c != 'L')
		return (-1);
	if (c == 'M')
		return (0);
	if (c == 'L')
		return (1);
	return (0);
}

int							play_game(int *matches, int rows, int highest)
{
	int		i;
	int		turn;

	i = rows - 1;
	turn = -3;
	while (turn < 0)
		turn = prompt_for_start(turn);
	ft_putchar('\n');
	while (turn >= 0)
	{
		put_board(matches, rows, highest);
		if (turn == 1)
			turn = lucifer_turn(matches, i);
		else
			turn = player_turn(matches, i);
		if (matches[i] == 0)
			i--;
		if (turn >= 0)
			turn = switchturn(turn);
		else
			return (who_wins(turn));
	}
	return (1);
}
