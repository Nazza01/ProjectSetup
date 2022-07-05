/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 15:42:52 by Nathanael        ###   ########.fr       */
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
	//	copy correct typed files into .temp dir with same dir structure (*.c goes into sources), *.h goes into headers and others where they need
	//	Ask if git wants to be setup, if so set it up
	// If not say okay cool good lets keep going
	// Move files into final dest (get from project.dir)
	// Final confirm, files are going to be moved from one place to another, if you are happy with it type yes, otherwise no then re-setup again
	//	Print message if move went correctly using system(ls $dir) or something
	// Log messages
	return 0;
}
