/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:23:13 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 21:34:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exeggcute(char **cmd, char *path, char **envp)
{
	int		check;

	check = execve(path, cmd, envp);
	ft_printf("Error: execve failed\n");
	exit(check);
}

void	executor_path(t_token *token, char *envp[])
{
	pid_t	pid;
	int		status;

	token->path = get_path(envp, token->cmd[0]);
	if (!token->path)
		ft_printf("%s: command not found\n", token->value);
	else
	{
		pid = fork();
		handle_signal_child();
		if (pid == -1)
			ft_printf("Error: fork failed\n");
		else if (pid == 0)
		{
			handle_signal();
			exeggcute(token->cmd, token->path, envp);
		}
		else
			wait(&status);
	}
}

/**
 * @brief Function that executes the command sent by the user.
 * @param input Command sent by the user.
 * @return void
 */
void	executor(t_token *token, char *envp[])
{
	char	*input;

	input = token->cmd[0];
	if (!ft_strncmp(input, "echo", 5))
		ft_echo(input);
	else if (!ft_strncmp(input, "cd", 3))
		ft_cd(input);
	else if (!ft_strncmp(input, "pwd", 4))
		ft_pwd(input);
	else if (!ft_strncmp(input, "export", 7))
		ft_export(input);
	else if (!ft_strncmp(input, "unset", 6))
		ft_unset(input);
	else if (!ft_strncmp(input, "env", 4))
		ft_env(input);
	else if (!ft_strncmp(input, "exit", 5))
		ft_exit(token);
	else
		executor_path(token, envp);
}
