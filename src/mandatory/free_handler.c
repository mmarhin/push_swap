/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:56:05 by dukim             #+#    #+#             */
/*   Updated: 2025/09/29 10:17:13 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	free_split_str(char **split)
{
	char	**temp;

	temp = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(temp);
}

void	free_stack(t_stack *sa, t_stack *sb)
{
	ft_lstclear(&(sa->header), free);
	if (sb)
		ft_lstclear(&(sb->header), free);
	free(sa);
	if (sb)
		free(sb);
}
