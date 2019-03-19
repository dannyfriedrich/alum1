/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:55:46 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/18 17:55:48 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *todelete;
	t_list *temp;

	todelete = *alst;
	while (todelete != NULL)
	{
		temp = todelete;
		todelete = todelete->next;
		del(temp->content, temp->content_size);
		free(temp);
	}
	*alst = NULL;
}
