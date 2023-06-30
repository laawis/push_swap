/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:57:14 by gaollier          #+#    #+#             */
/*   Updated: 2023/06/30 11:58:06 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return (-1);
	stack_swap(stack_a);
	stack_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return (-1);
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return (-1);
	stack_reverse_rotate(stack_a);
	stack_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
