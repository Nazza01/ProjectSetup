/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/06 14:17:35 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

int	main(void)
{
	ProjectSetup	project;

	if (project.PreSetup() == EXIT_FAILURE)		//	Pre Setup - temp dir
		project.LogToFile("Pre-Setup: .temp already exists, continuing");

	if (project.AskType() == EXIT_FAILURE)		//	Type of project to be made
		project.LogToFile("AskType: Failure");		

	if (project.AskDir() == EXIT_FAILURE)		//	Directory to put the files into
		project.LogToFile("AskDir: Failure");

	if (project.AskName() == EXIT_FAILURE)		//	Ask the name of the project
		project.LogToFile("AskName: Failure");

	if (project.CopyFiles() == EXIT_FAILURE)	//	Make file structure using this->Dir
		project.LogToFile("CopyFiles: Failure");

	if (project.AskSourceControl() == EXIT_FAILURE)	//	Ask if want git repo
		project.LogToFile("AskSourceControl: Failure");

	if (project.FinalSetup() == EXIT_FAILURE)	//	Move files from ./.temp to destination directory
		project.LogToFile("FinalSetup: Failure");
	
	return 0;
}
