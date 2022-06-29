/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Destructor.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:25:32 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:50:33 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

ProjectSetup::~ProjectSetup(void)
{
	this->LogToFile("ProjectSetup::ProjectSetup(void): Destructor called");
	this->LogToFile("ProjectSetup::ProjectSetup(void): Removing .temp/ directory");
	system("rmdir .temp/");
	// system("rm SetupLog_*.txt");
}
