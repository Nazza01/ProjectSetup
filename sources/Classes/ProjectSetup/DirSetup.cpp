/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirSetup.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:15 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:02:41 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::DirSetup(void)
{
	this->LogToFile("Pre-Setup: Attempting to make .temp directory");
	if (system("mkdir -p .temp/"))
	{
		this->LogToFile("Pre-Setup: Directory .temp successfully made");
		this->LogToFile("Pre-Setup: DirSetup() return true");
		return true;
	}
	else
	{
		this->LogToFile("Pre-Setup: Directory .temp was unsuccessful");
		this->LogToFile("Pre-Setup: DirSetup() return false");
		return false;
	}
}
