/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:57:57 by dukim             #+#    #+#             */
/*   Updated: 2025/10/07 17:34:21 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*sa;
	t_stack	*sb;

	if (argc <= 1)
		return (0);
	sa = generate_stack(argc, argv);
	sb = generate_stack(0, 0);
	if (!sa || !sb)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(sa, sb);
		return (0);
	}
	sa->name = 'A';
	sb->name = 'B';
	push_swap(sa, sb, sa->len);
	free_stack(sa, sb);
}
