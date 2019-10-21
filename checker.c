/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2019/10/02 11:29:06 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_instruction(t_array *stack, char *instr)
{
	if (ft_strequ(instr, "sa"))
		ft_sa(stack);
	else if (ft_strequ(instr, "sb"))
		ft_sb(stack);
	else if (ft_strequ(instr, "ss"))
		ft_ss(stack);
	else if (ft_strequ(instr, "pa"))
		ft_pa(stack);
	else if (ft_strequ(instr, "pb"))
		ft_pb(stack);
	else if (ft_strequ(instr, "ra"))
		ft_ra(stack);
	else if (ft_strequ(instr, "rb"))
		ft_rb(stack);
	else if (ft_strequ(instr, "rr"))
		ft_rr(stack);
	else if (ft_strequ(instr, "rra"))
		ft_rra(stack);
	else if (ft_strequ(instr, "rrb"))
		ft_rrb(stack);
	else if (ft_strequ(instr, "rrr"))
		ft_rrr(stack);
	else
		return (-1);
	return (0);
}

static void	do_instruction(t_array *stack)
{
	char *instr;

	while (get_next_line(0, &instr) > 0)
	{
		if (!instr)
			break ;
		if (get_instruction(stack, instr))
		{
			ft_putstr_fd("Error\n", 2);
			free_array(stack);
			free(instr);
			exit(1);
		}
		free(instr);
		instr = NULL;
	}
	free(instr);
}

static void	split_args(int argc, char **argv, t_array *stack)
{
	argv = ft_strsplit(argv[0], ' ');
	argc = 0;
	while (argv && argv[argc])
		argc++;
	if (argc == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(stack);
		exit(1);
	}
}

int			main(int argc, char **argv)
{
	t_array			*stack;

	(argc-- == 1) ? exit(0) : argv++;
	stack = (t_array *)malloc(sizeof(t_array));
	if (argc == 1)
		split_args(argc, argv, stack);
	init_array_struct(stack, argc, 0);
	stack = parse_args(argc, argv, stack, 0);
	if (!(is_sorted(stack->array_a, stack->size_a)))
		do_instruction(stack);
	if (is_sorted(stack->array_a, stack->size_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_array(stack);
	return (0);
}
