/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:39:39 by dukim             #+#    #+#             */
/*   Updated: 2025/09/24 19:04:12 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (!lst || !new)
		return ;
	tail = ft_lstlast(*lst);
	tail->next = new;
	new->prev = tail;
}
