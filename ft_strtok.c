/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:47:46 by walter            #+#    #+#             */
/*   Updated: 2025/01/27 14:48:21 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *s, char *sep)
{
	static char	*current = NULL;
	static int	s_len;
	static int	i;

	if (!s && !current)
		return (NULL);
	if (s)
	{
		current = s;
		s_len = (int)ft_strlen(s);
		i = 0;
	}
	if (!current[i])
		i++;
	i += (int)ft_strspn(&current[i], sep);
	if (i >= s_len)
		return (current = NULL, NULL);
	s = &current[i];
	i += (int)ft_strcspn(&current[i], sep);
	if (i < s_len)
		current[i] = '\0';
	return (s);
}

/*int	main(void)
{
	char	s[] = "hello, World ! How are you doing ?";
	char	s2[] = "Hey, very good indeed ! And you ?";
	char	*token;

	printf("null return hopefully : %s\n", ft_strtok(NULL, " "));
	token = ft_strtok(s, " ");
	while (token)
	{
		printf("%s\n", token);
		token = ft_strtok(NULL, " ");
	}
	token = ft_strtok(s2, " ");
	while (token)
	{
		printf("%s\n", token);
		token = ft_strtok(NULL, " ");
	}
	return (0);
}
*/
