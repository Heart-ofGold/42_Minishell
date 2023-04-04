/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:39:33 by feralves          #+#    #+#             */
/*   Updated: 2023/04/04 03:44:03 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		ft_printf("[%d] %s.\n", temp->type, temp->value);
		temp = temp->next_cmd;
	}
	temp = tokens->next_redirection;
	while (temp)
	{
		ft_printf("[%d] %s.\n", temp->type, temp->value);
		temp = temp->next_redirection;
	}
	free(temp);
}

void	test_parser(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("\tTesting parser:\n");
	while (i <= parser->n_cmds)
	{
		j = 0;
		while (parser->cmd[i][j])
		{
			ft_printf("\t\tcmd %d:%d: %s\n", i, j, parser->cmd[i][j]);
			j++;
		}
		i++;
	}
}
