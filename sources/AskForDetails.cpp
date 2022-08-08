/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AskForDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:41 by Nathanael         #+#    #+#             */
/*   Updated: 2022/08/08 10:38:12 by Nathanael        ###   ########.fr       */
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
	int			dirCheck;
	string		path	=	TEMPDIR;

	cout << path << endl;
	cout << "What directory would you like this folder to be in?" << endl;
	cout << "Please write either one of:" << endl;
	cout << "Relative path: (./temp, ../temp, ../Desktop or ../../Desktop)" << endl;
	cout << "Absolute path: (~/temp, ~/Desktop or /home/$USER/development)" << endl;
	cout << "Directory: ";
	cin >> this->Directory;
	while (this->Directory.empty())
	{
		cout << "Directory cannot be empty: ";
		cin >> this->Directory;
	}
	
	this->FinalDir = this->Directory;
	dirCheck = 0;
	// dirCheck = mkdir(path.append(this->Directory).c_str(), 0777);
	if (dirCheck == 0)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
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

bool	ProjectSetup::AskSourceControl(void)
{
	cout << "Would you like to initialise a git repository for this project?" << endl;
	cout << "[Y y] to confirm or [N n] to decline: ";
	while (cin >> this->SourceAns && ((this->SourceAns.size() != 1 ) || \
			(this->SourceAns[0] != 'Y' && this->SourceAns[0] != 'y' && \
			this->SourceAns[0] != 'N' && this->SourceAns[0] != 'n')))
	{
		cout << "[Y y] to confirm or [N n] to decline: ";
	}
	this->LogToFile("AskSourceControl: Git initalisation answer is", this->SourceAns);	
	// Create files and use system to do git init
	// If file creation worked, then exit success
	// Otherwise failed
	return EXIT_SUCCESS;
}
