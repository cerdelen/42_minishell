/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:25:44 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 14:33:51 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <stdlib.h>
# include "minishell.h"

static void		sigint_handler(int signal);
void			handle_sigs_interactive(void);
static void		child_signal_handler(int signal);
void			handle_child_signals(void);
#endif
