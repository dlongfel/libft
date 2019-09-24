/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 06:57:08 by richardbrac       #+#    #+#             */
/*   Updated: 2019/09/24 06:57:15 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	unsigned char	*mem;

	buf = (unsigned char *)dst;
	mem = (unsigned char*)src;
	if (buf == mem)
		return (dst);
	if (src >= dst)
		while (len--)
			*buf++ = *mem++;
	else
	{
		buf += len - 1;
		mem += len - 1;
		while (len--)
			*buf-- = *mem--;
	}
	return (dst);
}
