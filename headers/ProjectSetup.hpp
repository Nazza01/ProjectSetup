/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 12:00:35 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>

void	LogtoFile(std::string msg);
bool	DirSetup(void);
bool	InitSetup(void);

#endif