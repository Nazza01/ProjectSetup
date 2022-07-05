/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AskForDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:41 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 15:14:00 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::AskType(void)
{
	cout << "What project type would you like this project to be?" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "[" << i << "]: " << Type_Headings[i];
		if (i == 0)
			cout << "\t\t";
		else
			cout << "\t";
		cout << "-\t" << Type_FileList[i] << endl;
	}
	cout << "Type[0-5]: ";
	cin >> this->Type;
	while (intRangeCheck(0, 5, this->Type) != true)
	{
		cout << "Type[0-5]: ";
		cin >> this->Type;		
	}
	this->type_iter = stoi(this->Type);
	this->LogToFile("AskType(): Project Type is:", this->Type_Headings[this->type_iter]);
	this->LogToFile("AskType(): Project Files are:", this->Type_FileList[this->type_iter]);
	return EXIT_SUCCESS;
}

bool	ProjectSetup::AskDir(void)
{
	cout << "What directory would you like this folder to be in? ";
	cin >> this->Directory;
	while (this->Directory.empty())
	{
		cout << "Directory cannot be empty: ";
		cin >> this->Directory;
	}
	this->LogToFile("AskDir: Project Directory is", this->Directory);
	return EXIT_SUCCESS;
}

bool	ProjectSetup::AskName(void)
{
	cout << "What would you like the name of the project to be? ";
	cin >> this->Name;
	while (this->Name.empty())
	{
		cout << "Name cannot be empty: ";
		cin >> this->Name;
	}
	this->LogToFile("AskName: Project Name is", this->Name);
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
