/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 14:06:11 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 12:13:30 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		min;
	int		i;

	temp = (*a);
	min = get_min_int(temp);
	i = 1;
	while (temp->content != min)
	{
		i++;
		temp = temp->next;
	}
	temp = (*a);
	if (i > 2)
	{
		while (temp->content != min)
			r_rotate_ab(&temp, 'a');
	}
	else if (i == 2)
	{
		while (temp->content != min)
			swap(&temp, 'a');
	}
	push_ab(&temp, b, 'b');
	(*a) = temp;
}

static int	sort_input_three(t_stack **a)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = (*a);
	while (!is_sorted(temp))
	{
		if (temp->content > temp->next->content)
			swap(&temp, 'a');
		else if (get_max_int(temp) == temp->content)
			rotate_ab(&temp, 'a');
		else
			r_rotate_ab(&temp, 'a');
	}
	(*a) = temp;
	return (EXIT_SUCCESS);
}

static int	sort_input_four_five(t_stack **a, t_stack **b, int argc)
{
	if (argc == 5)
		push_min(a, b);
	push_min(a, b);
	sort_input_three(a);
	push_ab(b, a, 'a');
	if (argc == 5)
		push_ab(b, a, 'a');
	free(*b);
	return (EXIT_SUCCESS);
}

int	sort_stack(t_stack **a, t_stack **b, int argc)
{
	if (is_sorted(*a))
		return (EXIT_SUCCESS);
	if (argc == 3)
		sort_input_three(a);
	if (argc == 4 || argc == 5)
		sort_input_four_five(a, b, argc);
	if (argc > 5)
	{
		index_stack(a);
		radix_sort(a, b, stack_len(*a));
	}
	if (is_sorted(*a))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
