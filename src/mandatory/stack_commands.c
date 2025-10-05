/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:26:17 by dukim             #+#    #+#             */
/*   Updated: 2025/10/05 11:55:47 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	push(t_stack *to, t_stack *from)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!from->header)
		return ;
	temp1 = to->header;
	temp2 = from->header->next;
	to->header = from->header;
	to->header->next = temp1;
	if (temp1)
		temp1->prev = to->header;
	from->header = temp2;
	if (from->header)
		from->header->prev = 0;
	else
		from->tail = 0;
	if (!to->tail)
		to->tail = to->header;
	to->len++;
	from->len--;
}

void	swap(t_stack *stack)
{
	int	*temp;

	if (!stack->header || !stack->header->next)
		return ;
	temp = stack->header->content;
	stack->header->content = stack->header->next->content;
	stack->header->next->content = temp;
}

void	rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack->header || !stack->header->next)
		return ;
	first = stack->header;
	second = first->next;
	second->prev = 0;
	stack->header = second;
	first->next = 0;
	first->prev = stack->tail;
	stack->tail->next = first;
	stack->tail = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*before;

	if (!stack->header || !stack->header->next)
		return ;
	last = stack->tail;
	before = last->prev;
	before->next = 0;
	stack->tail = before;
	last->prev = 0;
	last->next = stack->header;
	stack->header->prev = last;
	stack->header = last;
}
