/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:25:32 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:08:46 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

ProjectSetup::ProjectSetup(void)
{
	this->LogToFile("------------------ PROJECT_SETUP ------------------");
	this->LogToFile("ProjectSetup::ProjectSetup(void): Constructor called");
}

ProjectSetup::~ProjectSetup(void)
{
	this->LogToFile("ProjectSetup::ProjectSetup(void): Destructor called");
	// system("rmdir .temp/");
	// system("rm SetupLog_*.txt");
}
