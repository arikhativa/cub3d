/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2023/02/07 10:47:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define PIPE_CHAR				'|'
# define RR_CHAR				'>'
# define RL_CHAR				'<'
# define NEW_LINE_CHAR			'\n'
# define NEW_LINE_STR			"\n"
# define SINGLE_QUOTE_CHAR		'\''
# define DOUBLE_QUOTE_CHAR		'\"'
# define DOUBLE_QUOTE_STR		"\""
# define TAB_CHAR         '\t'
# define SPACE_CHAR				' '
# define EQUAL_CHAR				'='
# define UNDERSCORE_CHAR		'_'
# define MINUS_CHAR				'-'
# define N_CHAR					'n'
# define PLUS_CHAR				'+'
# define EQUAL_STR				"="
# define COLON_CHAR				':'
# define DOT_CHAR				'.'
# define SLASH_CHAR				'/'
# define SLASH_STR				"/"
# define QUOTE_STR				"'"
# define MAIN_PROMPT			"\e[0mmsh$ "
# define DQUOTE_PROMPT			"\e[0mdquote> "
# define SQUOTE_PROMPT			"\e[0mquote> "
# define HEREDOC_PROMPT			"\e[0m> "
# define EMPTY_STRING			""
# define NEW_PROC				0
# define C_FLAG_STR				"-c"
# define EXPANDER_CHAR			'$'
# define TILDE_CHAR				'~'
# define EXPANDER_STRING		"$"
# define QUESTION_MARK_CHAR		'?'
# define R_BRACKET				')'
# define L_BRACKET				'('
# define MINISHELL_STR			"\e[0mminishell"
# define EXEC_CMD_NOT_FOUND_STR	"command not found: "
# define PIPE_LIMIT_ERROR_STR	"pipe limit reached"
# define EXEC_PREM_ERR_STR		"permission denied: "
# define UNSET_INVALID_ERR_STR	"': not a valid identifier"
# define CD_INVALID_PATH_STR	": No such file or directory"
# define CD_TOO_MANY_ARGS		"too many arguments"
# define CD_ERR_STR				"cd: "
# define HEREDOC_ERR_STR		"heredoc: "
# define HEREDOC_INTER_ERR_STR	"heredoc are only available on interactive mode"
# define CD_HOME_ERR_STR		"HOME not set"
# define EXPORT_INVALID_ARG		"\': not a valid identifier"
# define EXPORT_ERR_STR			"export: `"
# define UNSET_ERR_STR			"unset: `"
# define EXIT_ERR_STR			"exit: "
# define SYNTAX_ERROR_STR		"syntax error near token `"
# define SYNTAX_ERROR_RET_VAL	258
# define EXIT_NUM_ERR_STR		": numeric argument required"
# define EXIT_TOO_MANY_ARGS		"too many arguments"
# define EXEC_DIR_ERR_STR		": Is a directory"
# define SIGQUIT_STR			"Quit: "
# define PIPE_READ				0
# define PIPE_WRITE				1
# define PWD_VAR				"PWD"
# define OLDPWD_VAR				"OLDPWD"
# define HOME_VAR				"HOME"
# define HEREDOC_TMP_PATH		"/tmp/hd_file"
# define EXPORT_PREFIX			"declare -x "
# define PIPE_LIMIT				70

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
