/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotade.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:12:52 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/09 10:33:32 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotade_bis(int *pile, int len)
{
	int	temp;

	temp = pile[0];
	move_up(pile, len);
	pile[len - 1] = temp;
}

void	r_rotade_bis(t_all *all, char *instruction)
{
	if (ft_strcmp(instruction, "ra") == 0)
		rotade_bis(all->a_bis, all->data.a_len);
	if (ft_strcmp(instruction, "rb") == 0)
		rotade_bis(all->b_bis, all->data.b_len);
	if (ft_strcmp(instruction, "rr") == 0)
	{
		rotade_bis(all->a_bis, all->data.a_len);
		rotade_bis(all->b_bis, all->data.b_len);
	}
}
