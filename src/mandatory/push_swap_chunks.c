/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:40:00 by mamarin-         #+#    #+#             */
/*   Updated: 2025/10/07 12:40:00 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

#define CHUNK 0
#define LIMIT 1
#define PUSHED 2
#define SIZE 3

static int	get_chunk_size(int size)
{
	if (size <= 5)
		return (size);
	if (size <= 100)
		return (size / 5 + (size % 5 != 0));
	if (size <= 500)
		return (16);
	return (20);
}

static void	process_current(t_stack *sa, t_stack *sb, int *data)
{
	int	val;

	val = *(int *)sa->header->content;
	if (val >= data[LIMIT])
	{
		command_controller(sa, 0, 5);
		return ;
	}
	command_controller(sa, sb, 4);
	if (val < data[LIMIT] - data[CHUNK] / 2 && sb->len > 1)
		command_controller(0, sb, 6);
	if (++data[PUSHED] == data[CHUNK]
		&& sb->len < (unsigned int)data[SIZE])
	{
		data[LIMIT] += data[CHUNK];
		data[PUSHED] = 0;
	}
}

static void	push_chunks(t_stack *sa, t_stack *sb, int size)
{
	int	data[4];

	normalize_indices(sa);
	data[CHUNK] = get_chunk_size(size);
	data[LIMIT] = data[CHUNK];
	data[PUSHED] = 0;
	data[SIZE] = size;
	while (sa->len)
		process_current(sa, sb, data);
}

void	chunk_sort(t_stack *sa, t_stack *sb, int size)
{
	int	pos;

	push_chunks(sa, sb, size);
	while (sb->len)
	{
		pos = get_max_pos(sb);
		rotate_to_top_b(sb, pos);
		command_controller(sa, sb, 3);
	}
}
