/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   askForDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:41 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 23:57:04 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

void	ProjectSetup::AskType(void)
{
	std::cout << "What project type would you like this project to be?" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << this->Type_Headings[i] << "\t - \t" << this->Type_FileList[i] << std::endl;
	while (intRangeCheck(0, 5, this->Type) != true)
		std::getline(std::cin, this->Type);
	this->LogToFile("askType(): project type has been set to ", this->Type);
}

void	ProjectSetup::AskDir(void)
{
	std::cout << "What directory would you like this folder to be in?" << std::endl;
	while (!(this->Directory.empty()))
	{
		// todo: See if there is a better way of implementing this using c++17 or 11 features
		std::getline(std::cin, this->Directory);
	}
}

bool	ProjectSetup::AskName(void)
{
	std::cout << "What would you like the name of the project to be? ";
	std::cin >> this->Name;
	return (this->CheckEmpty(this->Name));
}

bool	ProjectSetup::AskAgain(void)
{
	if (this->AskName() == EXIT_SUCCESS && this->AskDir() == EXIT_SUCCESS && this->AskType() == EXIT_SUCCESS)
		return EXIT_SUCCESS;
	else if (this->AskName() == EXIT_FAILURE|| this->AskDir() == EXIT_FAILURE || this->AskType() == EXIT_FAILURE)
		return EXIT_FAILURE;
	else
	{
		this->LogToFile("askName(), askDir() or askType() is neither true or false");
		return EXIT_FAILURE;
	}
}
