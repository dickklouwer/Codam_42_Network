/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 11:01:11 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 11:06:57 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_till_empty(t_stack **src, t_stack **dst, char stack)
{
	int	i;

	i = stack_len(*src);
	while (i > 0)
	{
		push_ab(src, dst, stack);
		i--;
	}
	return ;
}

int	radix_sort(t_stack **a, t_stack **b, int s_len)
{
	int	j;
	int	i;
	int	num;

	i = 0;
	while (!is_sorted(*a))
	{
		j = 0;
		while (j < s_len)
		{
			num = (*a)->index;
			if (((num >> i) & 1) == 1)
				rotate_ab(a, 'a');
			else
				push_ab(a, b, 'b');
			j++;
		}
		push_till_empty(b, a, 'a');
		i++;
	}
	return (EXIT_SUCCESS);
}
