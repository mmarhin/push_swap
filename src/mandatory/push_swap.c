/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:38:58 by dukim             #+#    #+#             */
/*   Updated: 2025/10/07 12:23:07 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	push_swap(t_stack *sa, t_stack *sb, int size)
{
	if (is_sorted(sa, sa->len))
	{
		command_controller(sa, sb, 0);
		return ;
	}
	if (size <= 5)
		sort_upto5(sa, sb, size);
	else
		chunk_sort(sa, sb, size);
	command_controller(sa, sb, 0);
}
