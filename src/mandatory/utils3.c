/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:54:25 by dukim             #+#    #+#             */
/*   Updated: 2025/10/05 12:49:54 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	exec_s1_tail(t_stack *s1, t_stack *s2)
{
	if (s1->name == 'A')
	{
		command_controller(s1, s2, 7);
		command_controller(s1, s2, 4);
	}
	else
	{
		command_controller(s2, s1, 8);
		command_controller(s2, s1, 3);
	}
}

void	exec_s2_tail(t_stack *s1, t_stack *s2)
{
	if (s1->name == 'A')
		command_controller(s1, s2, 8);
	else
		command_controller(s2, s1, 7);
}

void	exec_s1_head(t_stack *s1, t_stack *s2)
{
	if (s1->name == 'A')
		command_controller(s1, s2, 4);
	else
		command_controller(s2, s1, 3);
}
