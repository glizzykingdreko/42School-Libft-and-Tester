/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampoba <dcampoba@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:51:23 by dcampoba          #+#    #+#             */
/*   Updated: 2023/04/30 20:51:31 by dcampoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	is_substring(char *str, const char *sub, size_t len)
{
	while (*sub && len-- > 0)
		if (*str++ != *sub++)
			return (0);
	if (*sub)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*runner;

	if (len == 0 && !big)
		return (NULL);
	runner = (char *) big;
	if (*little == '\0')
		return (runner);
	while (*runner && len > 0)
	{
		if (*runner == *little && is_substring(runner, little, len))
			return (runner);
		runner++;
		len--;
	}
	return (NULL);
}
