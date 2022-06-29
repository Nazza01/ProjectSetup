/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirSetup.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:15 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 12:14:42 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	DirSetup(void)
{
	// Make Dir .temp
	LogtoFile("Pre-Setup: Attempting to make .temp directory");
	if (system("mkdir .temp"))
	{
		LogtoFile("Pre-Setup: Directory .temp successfully made");
		return (true);
	}
	else
		return (false);
}
