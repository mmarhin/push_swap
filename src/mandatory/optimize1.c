/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:12:42 by dukim             #+#    #+#             */
/*   Updated: 2025/10/07 12:22:38 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

static void	run_command(t_stack *stack, int cmd_a, int cmd_b)
{
	if (stack->name == 'A')
		command_controller(stack, 0, cmd_a);
	else
		command_controller(0, stack, cmd_b);
}

static void	sort_three_base(t_stack *stack, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		run_command(stack, 1, 2);
	else if (first > second && second > third)
	{
		run_command(stack, 1, 2);
		run_command(stack, 7, 8);
	}
	else if (first > second && second < third && first > third)
		run_command(stack, 5, 6);
	else if (first < second && second > third && first < third)
	{
		run_command(stack, 1, 2);
		run_command(stack, 5, 6);
	}
	else if (first < second && second > third && first > third)
		run_command(stack, 7, 8);
}

void	sort_3_triangle(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || stack->len < 2 || is_sorted(stack, 3))
		return ;
	if (stack->len == 2)
	{
		first = *(int *)stack->header->content;
		second = *(int *)stack->header->next->content;
		if (first > second)
			run_command(stack, 1, 2);
		return ;
	}
	first = *(int *)stack->header->content;
	second = *(int *)stack->header->next->content;
	third = *(int *)stack->header->next->next->content;
	sort_three_base(stack, first, second, third);
}
