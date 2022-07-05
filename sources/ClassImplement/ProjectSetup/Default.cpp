/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:06:53 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 11:06:33 by Nathanael        ###   ########.fr       */
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
	// this->LogToFile("ProjectSetup::ProjectSetup(void): Removing .temp/ directory");
	// system("rmdir .temp/");
	// system("rm SetupLog_*.txt");
}
