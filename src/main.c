/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:09:24 by gaollier          #+#    #+#             */
/*   Updated: 2023/06/30 13:57:20 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

#include "stack.h"

static void	first_init_check(int argc, char **argv, t_stack **stack_a);
static int	second_init_check(t_stack **stack_a);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		first_init_check(argc, argv, &stack_a);
		if (second_init_check(&stack_a) == 0)
			return (0);
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) == 3)
			ft_sort_3(&stack_a);
		else if (stack_size(stack_a) == 5)
			ft_sort_5(&stack_a, &stack_b);
		else if (stack_size(stack_a) > 5)
			radix_sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
}

static void	first_init_check(int argc, char **argv, t_stack **stack_a)
{
	if (stack_init(argc, argv, stack_a) == -1)
	{
		free_stack(stack_a);
		exit_error();
	}
}

static int	second_init_check(t_stack **stack_a)
{
	if (stack_is_sorted(*stack_a, 1))
	{
		free_stack(stack_a);
		return (0);
	}
	else
		return (1);
}
