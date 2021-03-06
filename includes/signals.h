/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:25:44 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 19:41:28 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>

void	handle_sigs_interactive(void);
void	handle_child_signals(void);
void	handle_here_doc_signals_parent(void);
void	handle_here_doc_signals_child(void);
void	handle_here_doc_signals(void);
#endif
