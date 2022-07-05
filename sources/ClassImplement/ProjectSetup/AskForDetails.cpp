/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AskForDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:41 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 10:48:36 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::AskType(void)
{
	cout << "What project type would you like this project to be?" << endl;
	for (int i = 0; i < 5; i++)
		cout << this->Type_Headings[i] << "\t - \t" << this->Type_FileList[i] << endl;
	while (intRangeCheck(0, 5, this->Type) != true)
		getline(cin, this->Type);
	this->LogToFile("askType(): project type has been set to ", this->Type);
	return EXIT_SUCCESS;
}

bool	ProjectSetup::AskDir(void)
{
	cout << "What directory would you like this folder to be in?" << endl;
	while (!(this->Directory.empty()))
	{
		// todo: See if there is a better way of implementing this using c++17 or 11 features
		getline(cin, this->Directory);
	}
	return EXIT_SUCCESS;
}

bool	ProjectSetup::AskName(void)
{
	cout << "What would you like the name of the project to be? ";
	cin >> this->Name;
	while (!(this->Name.empty()))
	{
		// todo: See if there is a better way of implementing this using c++17 or 11 features
		getline(cin, this->Name);
	}
	return EXIT_SUCCESS;
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
