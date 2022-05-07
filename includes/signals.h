/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:25:44 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/07 19:59:05 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <stdlib.h>
# include "minishell.h"

// void init_sigs_parent(t_ms_data *data);
// void init_sigs_children(t_ms_data *data);
// void init_sigs_parent(t_ms_data *data);
// void handle_sigint_parent(int sig);


// static void	sigint_handler(int signal);
// void		handle_parent_signals(void);
// static void	child_signal_handler(int signal);
// void		handle_child_signals(void);

void	sigint_handler(int signal);
void	handle_parent_signals(t_ms_data *data);
void	child_signal_handler(int signal);
void	handle_child_signals(t_ms_data *data);
#endif
