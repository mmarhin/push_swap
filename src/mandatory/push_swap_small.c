/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:40:00 by mamarin-         #+#    #+#             */
/*   Updated: 2025/10/07 12:40:00 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	sort_3_triangle(t_stack *sa)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)sa->header->content;
	second = *(int *)sa->header->next->content;
	third = *(int *)sa->header->next->next->content;
	if (first < second && second > third && first > third)
		command_controller(sa, 0, 7);
	else if (first > second && second < third && first > third)
		command_controller(sa, 0, 5);
	else if (first > second && second > third)
	{
		command_controller(sa, 0, 5);
		command_controller(sa, 0, 1);
	}
	else if (first < second && second > third && first < third)
	{
		command_controller(sa, 0, 7);
		command_controller(sa, 0, 1);
	}
	else if (first > second && second < third && first < third)
		command_controller(sa, 0, 1);
	command_controller(sa, 0, 0);
}

void	sort_upto5(t_stack *sa, t_stack *sb, int size)
{
	int	pos;
	int	to_push;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (*(int *)sa->header->content > *(int *)sa->header->next->content)
			command_controller(sa, 0, 1);
		return ;
	}
	while (sa->len > 3)
	{
		pos = get_min_pos(sa);
		rotate_to_top_a(sa, pos);
		command_controller(sa, sb, 4);
	}
	sort_3_triangle(sa);
	to_push = sb->len;
	while (to_push--)
		command_controller(sa, sb, 3);
}
