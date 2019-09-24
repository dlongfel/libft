/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 07:00:58 by richardbrac       #+#    #+#             */
/*   Updated: 2019/09/24 07:00:58 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (size > size + 1)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr)
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
	return (NULL);
}
