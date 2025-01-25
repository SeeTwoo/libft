/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:47:46 by walter            #+#    #+#             */
/*   Updated: 2025/01/25 16:12:55 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtok(char *s, char *sep)
{
	static char		*current = NULL;
	static int		s_len;
	static int		i;

	if (!s && !current)
		return (NULL);
	if (s)
	{
		current = s;
		s_len = (int)ft_strlen(s);
		i = -1;
		while (++i < s_len)
			if (ft_strchr(sep, current[i]))
				current[i] = '\0';
		i = 0;
	}
	while (current[i] == '\0' && i < s_len)
		i++;
	if (i >= s_len)
		return (current = NULL, NULL);
	s = &current[i];
	while (current[i] && i < s_len)
		i++;
	return (s);
}

/*int	main(void)
{
	char	s[] = "hello, World ! How are you doing ?";
	char	s2[] = "Hey, very good indeed ! And you ?";
	char	*token;

	printf("null return hopefully : %s\n", ft_strtok(NULL, ' '));
	token = ft_strtok(s, ' ');
	while (token)
	{
		printf("%s\n", token);
		token = ft_strtok(NULL, ' ');
	}
	token = ft_strtok(s2, ' ');
	while (token)
	{
		printf("%s\n", token);
		token = ft_strtok(NULL, ' ');
	}
	return (0);
}
*/
