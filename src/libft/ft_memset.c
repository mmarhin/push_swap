/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:35:27 by dukim             #+#    #+#             */
/*   Updated: 2025/09/24 19:03:58 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*convert_s;
	unsigned char	convert_c;
	size_t			size;

	convert_s = (unsigned char *)s;
	convert_c = (unsigned char)c;
	size = 0;
	while (size < n)
	{
		convert_s[size] = convert_c;
		size++;
	}
	return ((void *)convert_s);
}
