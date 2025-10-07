/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:52:58 by dukim             #+#    #+#             */
/*   Updated: 2025/10/07 19:27:00 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../src/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	t_list			*header;
	t_list			*tail;
	unsigned int	len;
	char			name;
}					t_stack;

void				swap(t_stack *stack);
void				push(t_stack *to, t_stack *from);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

void				free_split_str(char **split);
void				free_stack(t_stack *sa, t_stack *sb);

int					is_sorted(t_stack *stack, unsigned int size);

void				command_controller(t_stack *sa, t_stack *sb, int cmd_num);

t_stack				*generate_stack(int argc, char *argv[]);

int					get_min_pos(t_stack *stack);
int					get_max_pos(t_stack *stack);
void				rotate_to_top_a(t_stack *sa, int pos);
void				rotate_to_top_b(t_stack *sb, int pos);
void				sort_upto5(t_stack *sa, t_stack *sb, int size);
void				chunk_sort(t_stack *sa, t_stack *sb, int size);
void				normalize_indices(t_stack *stack);

void				push_swap(t_stack *sa, t_stack *sb, int size);

#endif
