/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:19:29 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 16:25:09 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	operation(t_all *all, char *instruction)
{
	if (instruction[0] == 's')
		s_swap(all, instruction);
	else if (instruction[0] == 'p')
		p_push(all, instruction);
	else if (instruction[0] == 'r' && ft_strlen(instruction) == 2)
		r_rotade(all, instruction);
	else if (instruction[0] == 'r' && ft_strlen(instruction) == 3)
		r_reverse_rotade(all, instruction);
}

void	operation_bis(t_all *all, char *instruction)
{
	if (instruction[0] == 's')
		s_swap(all, instruction);
	else if (instruction[0] == 'p')
		p_push(all, instruction);
	else if (instruction[0] == 'r' && ft_strlen(instruction) == 2)
		r_rotade_bis(all, instruction);
	else if (instruction[0] == 'r' && ft_strlen(instruction) == 3)
		r_reverse_rotade_bis(all, instruction);
	all->op.count++;
}
