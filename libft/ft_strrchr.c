/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampoba <dcampoba@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:51:53 by dcampoba          #+#    #+#             */
/*   Updated: 2023/04/30 20:51:58 by dcampoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*runner;

	runner = (char *) s;
	while (*runner)
		runner++;
	while (runner >= s)
	{
		if (*runner == (char) c)
			return (runner);
		runner--;
	}
	return (NULL);
}
