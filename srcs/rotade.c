/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotade.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:12:52 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/29 14:18:26 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotade(int *pile, int len)
{
	int	temp;

	temp = pile[0];
	move_up(pile, len);
	pile[len - 1] = temp;
}

void	r_rotade(t_all *all, char *instruction)
{
	if (ft_strcmp(instruction, "ra") == 0)
		rotade(all->a, all->data.a_len);
	if (ft_strcmp(instruction, "rb") == 0)
		rotade(all->b, all->data.b_len);
	if (ft_strcmp(instruction, "rr") == 0)
	{
		rotade(all->a, all->data.a_len);
		rotade(all->b, all->data.b_len);
	}
	ft_putstr(instruction);
	ft_putchar('\n');
}
