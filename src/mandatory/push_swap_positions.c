/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_positions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:40:00 by mamarin-         #+#    #+#             */
/*   Updated: 2025/10/07 12:40:00 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_list	*ptr;
	int		min_val;
	int		min_pos;
	int		idx;

	if (!stack || !stack->header)
		return (0);
	ptr = stack->header;
	min_val = *(int *)ptr->content;
	min_pos = 0;
	idx = 0;
	while (ptr)
	{
		if (*(int *)ptr->content < min_val)
		{
			min_val = *(int *)ptr->content;
			min_pos = idx;
		}
		idx++;
		ptr = ptr->next;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *stack)
{
	t_list	*ptr;
	int		max_val;
	int		max_pos;
	int		idx;

	if (!stack || !stack->header)
		return (0);
	ptr = stack->header;
	max_val = *(int *)ptr->content;
	max_pos = 0;
	idx = 0;
	while (ptr)
	{
		if (*(int *)ptr->content > max_val)
		{
			max_val = *(int *)ptr->content;
			max_pos = idx;
		}
		idx++;
		ptr = ptr->next;
	}
	return (max_pos);
}
