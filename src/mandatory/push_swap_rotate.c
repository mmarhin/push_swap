/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:40:00 by mamarin-         #+#    #+#             */
/*   Updated: 2025/10/07 12:40:00 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	rotate_to_top_a(t_stack *sa, int pos)
{
	if (!sa)
		return ;
	if (pos <= (int)(sa->len / 2))
	{
		while (pos-- > 0)
			command_controller(sa, 0, 5);
		return ;
	}
	pos = sa->len - pos;
	while (pos-- > 0)
		command_controller(sa, 0, 7);
}

void	rotate_to_top_b(t_stack *sb, int pos)
{
	if (!sb)
		return ;
	if (pos <= (int)(sb->len / 2))
	{
		while (pos-- > 0)
			command_controller(0, sb, 6);
		return ;
	}
	pos = sb->len - pos;
	while (pos-- > 0)
		command_controller(0, sb, 8);
}
