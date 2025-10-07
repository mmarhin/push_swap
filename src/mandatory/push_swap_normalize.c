/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:40:00 by mamarin-         #+#    #+#             */
/*   Updated: 2025/10/07 12:40:00 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

static int	alloc_buffers(int **values, int **sorted, unsigned int len)
{
	*values = (int *)malloc(sizeof(int) * len);
	if (!*values)
		return (0);
	*sorted = (int *)malloc(sizeof(int) * len);
	if (!*sorted)
	{
		free(*values);
		return (0);
	}
	return (1);
}

static void	fill_arrays(t_list *node, int *values, int *sorted)
{
	unsigned int	i;

	i = 0;
	while (node)
	{
		values[i] = *(int *)node->content;
		sorted[i] = values[i];
		node = node->next;
		i++;
	}
}

static void	sort_int_array(int *arr, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	int				key;

	i = 1;
	while (i < len)
	{
		key = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > key)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
		i++;
	}
}

static void	assign_indexs(t_stack *stack, int *sorted, int *values,
		unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	t_list			*node;

	node = stack->header;
	i = 0;
	while (node && i < len)
	{
		j = 0;
		while (j < len && sorted[j] != values[i])
			j++;
		*(int *)node->content = (int)j;
		node = node->next;
		i++;
	}
}

void	normalize_indices(t_stack *stack)
{
	int	*values;
	int	*sorted;

	if (!stack || stack->len < 2)
		return ;
	if (!alloc_buffers(&values, &sorted, stack->len))
		return ;
	fill_arrays(stack->header, values, sorted);
	sort_int_array(sorted, stack->len);
	assign_indexs(stack, sorted, values, stack->len);
	free(values);
	free(sorted);
}
