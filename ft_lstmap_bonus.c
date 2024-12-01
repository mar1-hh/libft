/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:29:44 by msaadaou          #+#    #+#             */
/*   Updated: 2024/10/28 18:35:11 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_head;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	while (lst)
	{
		c = f(lst->content);
		temp = ft_lstnew(c);
		if (!temp)
		{
			del(c);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, temp);
		lst = lst->next;
	}
	return (new_head);
}
