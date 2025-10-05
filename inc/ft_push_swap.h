/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:52:58 by dukim             #+#    #+#             */
/*   Updated: 2025/10/05 12:49:54 by mamarin-         ###   ########.fr       */
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

typedef struct s_is
{
	char			is_max;
	char			is_a;
	char			is_3;
}					t_is;

typedef struct s_size
{
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	s3;
}					t_size;

void				swap(t_stack *stack);
void				push(t_stack *to, t_stack *from);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

void				free_split_str(char **split);
void				free_stack(t_stack *sa, t_stack *sb);

t_list				*get_node3(t_stack *s1, t_stack *s2, t_size ts, int is_max);
int					is_sorted(t_stack *stack, unsigned int size, char is_max);
int					is_swap(t_stack *stack, int is_max);
t_size				cal_size3(int size);
t_is				is_return(t_is is, int n);

void				exec_s1_tail(t_stack *s1, t_stack *s2);
void				exec_s2_tail(t_stack *s1, t_stack *s2);
void				exec_s1_head(t_stack *s1, t_stack *s2);

void				drop_triangle_bottom(t_stack *stack, unsigned int size);
void				sort_3_triangle(t_stack *stack, char is_max);
int					earlyreturn_sorted_stack(t_stack *sa, t_stack *sb,
						unsigned int size, t_is is);
void				command_controller(t_stack *sa, t_stack *sb, int cmd_num);

t_stack				*generate_stack(int argc, char *argv[]);

void				push_swap(t_stack *sa, t_stack *sb, int size);

#endif