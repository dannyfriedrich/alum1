/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/17 12:53:47 by dfreire       #+#    #+#                 */
/*   Updated: 2019/03/17 12:53:47 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int						who_wins(int decide)
{
	if (decide == -2)
		lucifer_wins();
	else
		player_wins();
	return (1);
}

void					lucifer_wins(void)
{
	ft_writeincolours(" (        )   (         (             \n \
)\\ )  ( /(   )\\ )      )\\ )          \n\
(()/(  )\\()) (()/( (   (()/(          \n", "yellow");
	ft_writeincolours(" /(_))((_)\\   /(_)))\\   /(_))         \n\
(_))    ((_) (_)) ((_) (_))           \n\
| |    / _ \\ / __|| __|| _ \\          \n\
| |__ | (_) |\\__ \\| _| |   / _  _  _  \n\
|____| \\___/ |___/|___||_|_\\(_)(_)(_)\n\n", "red");
}

void					player_wins(void)
{
	ft_writeincolours("     )    )                     (        )  \n  \
( /( ( /(           (  (      )\\ )  ( /(  \n  \
)\\()))\\())     (    )\\))(   '(()/(  )\\()) \n", "yellow");
	ft_writeincolours(" ((_)\\((_)\\      )\\  ((_)()\\ )  /(_))((_)\\  \n\
__ ((_) ((_)  _ ((_) _(())\\_)()(_))   _((_) \n\
\\ \\ / // _ \\ | | | | \\ \\((_)/ /|_ _| | \\| | \n \
\\ V /| (_) || |_| |  \\ \\/\\/ /  | |  | .` | \n  \
|_|  \\___/  \\___/    \\_/\\_/  |___| |_|\\_| \n", "red");
	ft_putstr("                                            \n");
}

void					start_game(void)
{
	ft_writeincolours(" (                  (    (          (     \n \
)\\ )          (    )\\ ) )\\ )       )\\ )  \n\
(()/(    (     )\\  (()/((()/(  (   (()/(  \n ", "yellow");
	ft_writeincolours("/(_))   )\\  (((_)  /(_))/(_)) )\\   /(_)) \n\
(_))  _ ((_) )\\___ (_)) (_))_|((_) (_))   \n\
| |  | | | |((/ __||_ _|| |_  | __|| _ \\  \n\
| |__| |_| | | (__  | | | __| | _| |   /  \n\
|____|\\___/   \\___||___||_|   |___||_|_\\  \n", "red");
	ft_putstr("                                          \n");
	ft_writeincolours("Can you beat ", "light yellow");
	ft_writeincolours("Lucifer", "red");
	ft_writeincolours("?\n\nTake 1 to 3 matches per row. The player who takes \
the last one ", "light yellow");
	ft_writeincolours("LOSES\n", "red");
	ft_writeincolours("Are you ready?\n\n", "light yellow");
}

int						lucifer_takes(int matches, int minus)
{
	matches = matches - minus;
	ft_writeincolours("Lucifer took ", "red");
	ft_putstr("\033[1;31m");
	ft_putnbr(minus);
	ft_putstr("\033[0;m");
	ft_putchar('\n');
	return (matches);
}
