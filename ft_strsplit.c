/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 07:01:14 by richardbrac       #+#    #+#             */
/*   Updated: 2019/09/24 07:01:15 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *str, char c)
{
	int			i;

	i = 0;
	while (*str)
	{
		if ((*str != c && *(str + 1) == c)
				|| ((*str) != c && *(str + 1) == '\0'))
			i++;
		str++;
	}
	return (i);
}

static char	*skip_c(char const *str, char c)
{
	while (*str == c && *str)
		str++;
	return ((char *)str);
}

static int	len_w(char *str, char c)
{
	size_t		i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static void	ft_clear(char **mas)
{
	while (*mas)
		free(*mas++);
	free(mas);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**mas;
	char		*str;
	size_t		w;

	if (!s ||
			!(mas = (char **)malloc(sizeof(char *) * (words(s, c) + 1))))
		return (NULL);
	w = words(s, c);
	if (w > w + 1)
		return (NULL);
	str = (char *)s;
	while (w--)
	{
		str = skip_c(str, c);
		if (!(*mas = ft_strnew(len_w(str, c))))
		{
			ft_clear(mas);
			return (NULL);
		}
		ft_strncpy(*mas, str, len_w(str, c));
		mas++;
		str += len_w(str, c);
	}
	*mas = NULL;
	return (mas - words(s, c));
}
