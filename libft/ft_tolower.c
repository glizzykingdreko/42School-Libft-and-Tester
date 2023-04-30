/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampoba <dcampoba@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:55:32 by dcampoba          #+#    #+#             */
/*   Updated: 2023/04/30 20:55:39 by dcampoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_uppercase(int c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

int	ft_tolower(int c)
{
	if (is_uppercase(c))
		return (c - 'A' + 'a');
	return (c);
}
