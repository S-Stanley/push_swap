/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:00:06 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/26 00:00:08 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_and_exit_arg(char **nbr)
{
	free_that_matrice(nbr);
	exit(0);
}