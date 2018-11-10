/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:49:15 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/16 18:10:58 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		skip_tab(int start, char *str, char c)
{
	while (str[start] == c)
		start++;
	return (start);
}

static int		split_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		i = skip_tab(i, str, c);
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

static void		*split_clean(char **str, int n)
{
	while (n >= 0)
	{
		if (str[n])
			free(str[n]);
		n--;
	}
	if (str)
		free(str);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	j;
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * split_count((char*)s, c) + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while (s[skip_tab(i, (char*)s, c)])
	{
		i = skip_tab(i, (char*)s, c);
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		split[n] = ft_strsub(s, i, j);
		if (!split[n++])
			return (split_clean(split, n));
		i += j;
	}
	split[n] = NULL;
	return (split);
}
