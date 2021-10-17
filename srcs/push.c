/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:09:29 by gmorange          #+#    #+#             */
/*   Updated: 2021/08/02 18:18:16 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *taker, int *taker_len, int *receiver, int *receiver_len)
{
	int	to_push;
	int	i;

	i = 0;
	if (*(taker_len) != 0)
	{
		to_push = taker[0];
		move_up(taker, *(taker_len));
		*(receiver_len) += 1;
		*(taker_len) -= 1;
		i = *(receiver_len);
		move_down(receiver, *(receiver_len));
		receiver[0] = to_push;
	}
}

void	p_push(t_all *all, char *instruction)
{
	if (ft_strcmp(instruction, "pa") == 0)
		push(all->b, &all->data.b_len, all->a, &all->data.a_len);
	if (ft_strcmp(instruction, "pb") == 0)
		push(all->a, &all->data.a_len, all->b, &all->data.b_len);
	ft_putstr(instruction);
	ft_putchar('\n');
}
