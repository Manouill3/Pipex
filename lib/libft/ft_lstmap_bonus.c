/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:52:01 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/17 14:59:12 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new;
	t_list	*result;
	int		cont;

	if (!lst || !f)
		return (0);
	result = NULL;
	while (lst)
	{
		new = NULL;
		cont = f(lst->content);
		if (cont)
			new = ft_lstnew(cont);
		if (!new)
		{
			ft_lstclear(&result);
			return (0);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
