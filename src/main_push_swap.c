/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:30:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 19:45:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
        ft_printf("push_swap Argv=%s\n", argv[0]);
    else
    {
        ft_printf("push_swap Args=%s\n", argv[1]);
    }
    return (0);
}