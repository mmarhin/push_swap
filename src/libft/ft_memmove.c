/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:56:16 by dukim             #+#    #+#             */
/*   Updated: 2025/09/24 19:03:56 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*convert_dest;
	unsigned char	*convert_src;
	size_t			size;

	if (dest == src)
		return (dest);
	if ((size_t)(dest - src) >= n)
		return (ft_memcpy(dest, src, n));
	convert_dest = (unsigned char *)dest;
	convert_src = (unsigned char *)src;
	size = n;
	while (--size > 0)
		convert_dest[size] = convert_src[size];
	*convert_dest = *convert_src;
	return ((void *)convert_dest);
}
