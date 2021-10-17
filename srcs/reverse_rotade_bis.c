/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:18:09 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/09 10:32:31 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	reverse_rotade_bis(int *pile, int len)
{
	int	temp;

	temp = pile[len - 1];
	move_down(pile, len);
	pile[0] = temp;
}

void	r_reverse_rotade_bis(t_all *all, char *instruction)
{
	if (ft_strcmp(instruction, "rra") == 0)
		reverse_rotade_bis(all->a_bis, all->data.a_len);
	if (ft_strcmp(instruction, "rrb") == 0)
		reverse_rotade_bis(all->b_bis, all->data.b_len);
	if (ft_strcmp(instruction, "rrr") == 0)
	{
		reverse_rotade_bis(all->a_bis, all->data.a_len);
		reverse_rotade_bis(all->b_bis, all->data.b_len);
	}
}
