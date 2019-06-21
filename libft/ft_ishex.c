/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:45:56 by kmira             #+#    #+#             */
/*   Updated: 2019/06/06 14:50:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ishex(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else if ('a' <= c && c <= 'f')
		return (1);
	else if ('A' <= c && c <= 'F')
		return (1);
	else
		return (0);
}
