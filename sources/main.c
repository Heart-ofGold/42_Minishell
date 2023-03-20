/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:10:34 by feralves          #+#    #+#             */
/*   Updated: 2023/03/19 22:03:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	testing_input(char *input)
{
	ft_printf("History: %s\n", input);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*input;

	(void)argc;
	(void)argv;
	while (1)
	{
		input = readline("pearl>$ ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
			testing_input(input);
		free(input);
	}
}
