/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:10:34 by feralves          #+#    #+#             */
/*   Updated: 2023/03/27 22:08:17 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	testing_input(char *input)
{
	ft_printf("You wrote: %s\n", input);
	return (0);
}

void	mini_loop(void)
{
	char	*input;

	while (1)
	{
		input = readline(PROMPT);
		if (check_input(input))
			continue ;
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			testing_input(input);
		free(input);
	}
}

int	main(int argc, char *argv[])
{
	if (argv && argc > 1)
	{
		ft_printf("Error: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	mini_loop();
}
