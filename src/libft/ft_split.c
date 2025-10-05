/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:36 by dukim             #+#    #+#             */
/*   Updated: 2025/09/24 19:03:45 by mamarin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_wordcnt(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		cnt++;
	}
	return (cnt);
}

static char	*make_str(char const *s, char c, int *index)
{
	char	*split;
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	split = (char *)malloc(sizeof(char) * (len + 1));
	if (!split)
		return (0);
	ft_strlcpy(split, s, len + 1);
	*index += len;
	return (split);
}

static void	*free_split(char **str_split, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(str_split[i]);
		i++;
	}
	free(str_split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	int		word_cnt;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	word_cnt = get_wordcnt(&s[i], c);
	str_split = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!str_split)
		return (0);
	str_split[word_cnt] = 0;
	j = -1;
	while (++j < word_cnt)
	{
		str_split[j] = make_str(&s[i], c, &i);
		if (!str_split[j])
			return (free_split(str_split, j));
		while (s[i] == c && s[i])
			i++;
	}
	return (str_split);
}
