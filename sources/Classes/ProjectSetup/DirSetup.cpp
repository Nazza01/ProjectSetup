/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirSetup.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:15 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:53:19 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::DirSetup(void)
{
	int	check = 0;

	this->LogToFile("Pre-Setup: Attempting to make .temp directory");
	check = mkdir(".temp", 07770);
	if (check)
	{
		this->LogToFile("Pre-Setup: .temp directory successfully created");
		return false;
	}
	else
	{
		this->LogToFile("Pre-Setup: .temp directory unable to be created");
		return true;
	}
}
