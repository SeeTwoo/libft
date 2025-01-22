/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:46:57 by walter            #+#    #+#             */
/*   Updated: 2025/01/13 16:06:00 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *s, char sep)
{
	static char	*current;

	if (s)
	{
		current = s;
		while (*current == sep)
			current++;
		if (!(*current))
			return (NULL);
		return (current);
	}
	while (*current != sep && *current)
		current++;
	while (*current == sep)
		current++;
	if (*current == '\0')
		return (NULL);
	return (current);
}

/*int	main(int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
		return (0);
	ptr = ft_strtok(av[1], ' ');
	while (ptr)
	{
		printf("%s\n", ptr);
		ptr = ft_strtok(NULL, ' ');
	}
	return (0);
}
*/
