/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 16:47:16 by fblom         #+#    #+#                 */
/*   Updated: 2019/02/15 17:54:29 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_putandclear(t_line *list, char **line, int ret)
{
	size_t		i;
	size_t		len;

	if (ret == -1)
		return (ret);
	if (ret == 0)
	{
		*line = NULL;
		return (ret);
	}
	i = ft_substring_size(list->string, '\n');
	*line = ft_strsub(list->string, 0, i);
	len = ft_strlen(list->string);
	if (i == 0)
		*line = ft_strdup("\0");
	list->string = ft_memmove(list->string, list->string + i + 1, len - i);
	((char *)list->string)[len - i] = '\0';
	if (ret == -3)
		list->string = NULL;
	return (1);
}

static int			ft_readlines(t_line *list, char **line, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	ret = BUFF_SIZE;
	if (!list->string)
		list->string = ft_strdup("\0");
	while (list->string && ft_strchr(list->string, '\n') == NULL && \
		ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1 || (ret == 0 && ft_strlen(list->string) == 0))
			return (ft_putandclear(list, line, ret));
		buf[ret] = '\0';
		if (ret == 0 && list->string)
			return (ft_putandclear(list, line, -3));
		temp = ft_strjoin(list->string, buf);
		free(list->string);
		list->string = temp;
	}
	if (list->string)
		return (ft_putandclear(list, line, 1));
	*line = NULL;
	return (0);
}

static t_line		*ft_addfirst(t_line *list, const int fd)
{
	list = (t_line *)malloc(sizeof(t_line));
	if (!list)
		return (NULL);
	list->string = ft_strdup("\0");
	list->fd = fd;
	list->next = NULL;
	return (list);
}

static t_line		*ft_searchormake(t_line *list, const int fd)
{
	t_line		*temp;

	while (list)
	{
		if (list->fd == fd)
			return (list);
		temp = list;
		list = list->next;
	}
	list = ft_addfirst(list, fd);
	temp->next = list;
	return (list);
}

int					get_next_line(const int fd, char **line)
{
	static t_line	*startlist;
	t_line			*pos;

	if (!startlist)
	{
		startlist = ft_addfirst(startlist, fd);
		pos = startlist;
	}
	else
	{
		pos = startlist;
		pos = ft_searchormake(pos, fd);
	}
	if (!pos)
		return (-1);
	return (ft_readlines(pos, line, fd));
}
