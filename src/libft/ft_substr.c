/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:43:32 by dukim             #+#    #+#             */
/*   Updated: 2025/09/24 19:03:38 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if ((size_t)start >= (size_t)s_len)
	{
		len = 0;
		start = (unsigned int)s_len;
	}
	if (s_len - (size_t)start < len)
		len = s_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
