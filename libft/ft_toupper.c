/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampoba <dcampoba@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:56:00 by dcampoba          #+#    #+#             */
/*   Updated: 2023/04/30 20:56:03 by dcampoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_lowercase(int c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	ft_toupper(int c)
{
	if (is_lowercase(c))
		return (c - 'a' + 'A');
	return (c);
}
