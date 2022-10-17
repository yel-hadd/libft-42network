/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:32:46 by yel-hadd          #+#    #+#             */
/*   Updated: 2022/10/17 18:02:56 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*join;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	join = malloc((slen1 + slen2) * sizeof(char));
	if (!join)
		return (0);
	while (*s1)
		*join ++ = *s1 ++;
	while (*s2)
		*join ++ = *s2 ++;
	return (join - slen1 - slen2);
}

/*

#include <stdio.h>

int main(void)
{
	char	*s1 = {"Hello"};
	char	*s2 = {"Hello"};

	printf("%s\n", ft_strjoin(s1, s2));
}
*/
