/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:06:02 by gaollier          #+#    #+#             */
/*   Updated: 2023/06/30 12:09:40 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;
	int	digit;

	digit = 1;
	size = stack_size(*stack_a);
	while (!stack_is_sorted(*stack_a, 1))
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->index & digit) > 0)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while (stack_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		digit = digit << 1;
	}
}

void	ft_sort_3(t_stack **stack)
{
	if ((*stack)->index == 2)
		ra(stack);
	else if ((*stack)->next->index == 2)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		if (((*stack_a)->index < (*stack_a)->next->index)
			&& (*stack_a)->index != 0 && (*stack_a)->index != 1)
			ra(stack_a);
		else if (((*stack_a)->index > (*stack_a)->next->index)
			&& (*stack_a)->index != 0 && (*stack_a)->index != 1)
			sa(stack_a);
		else if (((*stack_a)->index == 0 || ((*stack_a)->index == 1)))
			pb(stack_a, stack_b);
	}
	if ((*stack_a)->index == 4)
		ra(stack_a);
	else if ((*stack_a)->next->index == 4)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_b)->index == 1)
		sa(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_b)->index == 0)
		ss(stack_a, stack_b);
	if ((*stack_b)->index == 0)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
