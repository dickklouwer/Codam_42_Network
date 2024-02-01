/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 13:23:03 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/28 10:10:34 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (EXIT_FAILURE);
	if (parse_stack(&stack_a, argv, argc))
		return (EXIT_FAILURE);
	if (!sort_stack(&stack_a, &stack_b, argc - 1))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
