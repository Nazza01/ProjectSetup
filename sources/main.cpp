/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/30 00:03:33 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

int	main(void)
{
	ProjectSetup	project;

	project.PreSetup();					//Pre Setup - temp dir
	project.AskType();					//	Type of project to be made
	project.AskDir();					//	Directory to put the files into
	project.AskName();					//	Ask the name of the project
	// while (project.confirmAsk() != EXIT_SUCCESS) if the function doesnt recieve abosolute confirmation, then keep asking for re-setup;
	//	If that goes through, then great lets proceed
	//	copy correct typed files into .temp dir with same dir structure (*.c goes into sources), *.h goes into headers and others where they need
	//	Ask if git wants to be setup, if so set it up
	// If not say okay cool good lets keep going
	// Move files into final dest (get from project.dir)
	// Final confirm, files are going to be moved from one place to another, if you are happy with it type yes, otherwise no then re-setup again
	//	Print message if move went correctly using system(ls $dir) or something
	// Log messages
	return 0;
}
