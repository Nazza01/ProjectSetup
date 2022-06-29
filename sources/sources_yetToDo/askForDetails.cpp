/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   askForDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:41 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 14:22:58 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

static bool	checkEmpty(std::string str)
{
	if (str != "" || str != "\0")
	{
		logtoFile("checkEmpty(str): not empty string");
		return false;
	}
	else
	{
		logtoFile("checkEmpty(str): string is empty");
		return true;
	}
}

static bool	askType(void)
{
	std::cout << "What project type would you like this project to be?" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << proj.askType[i] << "\t - \t" << proj.askFiles[i] << std::endl;
	std::cin >> proj.Type;
	logtoFile("askType(): projec type has been set to " + proj.Type);
	return (false);
}

static bool	askDir(void)
{
	std::cout << "What directory would you like this folder to be in? ";
	std::cin >> proj.Directory;
	return (checkEmpty(proj.Directory));
}

static bool	askName(void)
{
	std::cout << "What would you like the name of the project to be? ";
	std::cin >> proj.Name;
	return (checkEmpty(proj.Name));
}

bool	askDetails(void)
{
	if (askName() == false || askDir() == false || askType() == false)
		return false;
	else if (askName() == true || askDir() == true || askType() == true)
		return true;
	else
	{
		logtoFile("askName(), askDir() or askType() is neither true or false");
		return true;
	}
}
