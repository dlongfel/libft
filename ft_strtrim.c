/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 07:01:35 by richardbrac       #+#    #+#             */
/*   Updated: 2019/09/24 07:01:36 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isws(int c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

char		*ft_strtrim(char const *s)
{
	char		*s_end;

	if (!s)
		return (NULL);
	while (ft_isws(*s))
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	s_end = (char *)(s + ft_strlen(s) - 1);
	while (ft_isws(*s_end))
		s_end--;
	return (ft_strndup((char *)s, s_end - s + 1));
}
