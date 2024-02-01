/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 13:30:53 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/28 10:14:44 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "limits.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

// STACK UTILS

t_stack	*ft_stcknew(int content);
t_stack	*ft_stcklast(t_stack *stack);
void	ft_stckadd_back(t_stack **lst, t_stack *new);
void	ft_putstack(t_stack *stack);

// SORT UTILS

int		get_min_int(t_stack *s);
int		get_max_int(t_stack *s);
int		stack_len(t_stack *s);

// INDEX STACK

void	index_stack(t_stack **s);

// PARSE STACK

int		parse_stack(t_stack **stack, char **argv, int argc);

// SORT

int		is_sorted(t_stack *stack);
int		sort_stack(t_stack **a, t_stack **b, int argc);

// RADIX SORT

int		radix_sort(t_stack **a, t_stack **b, int s_len);

// COMMANDS

void	push_ab(t_stack **src, t_stack **dst, int stack_in);
void	swap(t_stack **stack_a, int stack_in);
void	rotate_ab(t_stack **stack, int stack_in);
void	r_rotate_ab(t_stack **stack, int stack_in);

#endif