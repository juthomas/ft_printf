/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 02:57:52 by juthomas          #+#    #+#             */
/*   Updated: 2017/03/02 19:12:43 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char				*retour;
	int					i;

	i = 0;
	retour = NULL;
	retour = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!retour)
		return (NULL);
	while (i < ft_strlen(s))
	{
		retour[i] = (char)f(s[i]);
		i++;
	}
	retour[i] = '\0';
	return (retour);
}
