/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alum1.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 10:08:44 by fblom         #+#    #+#                 */
/*   Updated: 2019/03/16 10:08:44 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include <fcntl.h>
# include "libft/libft.h"

int			error_handling(char *string, int *rows, int fd);
int			get_data(char *string, int rows, int *highest, int fd);
void		put_board(int *matches, int rows, int highest);
int			play_game(int *matches, int rows, int highest);
int			put_errors(int error);
char		*get_input(int fd);
void		ft_writeincolours(char *str, char *colour);
void		start_game(void);
int			lucifer_takes(int matches, int minus);
void		player_wins(void);
void		lucifer_wins(void);
int			who_wins(int decide);

#endif
