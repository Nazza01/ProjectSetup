/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   askForDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:41 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:34:13 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::CheckEmpty(std::string str)
{
	if (str != "" || str != "\0")
	{
		this->LogToFile("checkEmpty(str): not empty string");
		return false;
	}
	else
	{
		this->LogToFile("checkEmpty(str): string is empty");
		return true;
	}
}

bool	ProjectSetup::AskType(void)
{
	std::cout << "What project type would you like this project to be?" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << this->askType[i] << "\t - \t" << this->askFiles[i] << std::endl;
	std::cin >> this->Type;
	this->LogToFile("askType(): projec type has been set to " + this->Type);
	return (false);
}

bool	ProjectSetup::AskDir(void)
{
	std::cout << "What directory would you like this folder to be in? ";
	std::cin >> this->Directory;
	return (this->CheckEmpty(this->Directory));
}

bool	ProjectSetup::AskName(void)
{
	std::cout << "What would you like the name of the project to be? ";
	std::cin >> this->Name;
	return (this->CheckEmpty(this->Name));
}

bool	ProjectSetup::AskDetails(void)
{
	if (this->AskName() == false || this->AskDir() == false || this->AskType() == false)
		return false;
	else if (this->AskName() == true || this->AskDir() == true || this->AskType() == true)
		return true;
	else
	{
		this->LogToFile("askName(), askDir() or askType() is neither true or false");
		return true;
	}
}
