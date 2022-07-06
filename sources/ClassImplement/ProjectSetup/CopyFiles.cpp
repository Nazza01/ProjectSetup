/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyFiles.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:55:32 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/06 10:13:02 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

void	ProjectSetup::CP(std::string SRC, std::string DST)
{
	string	cmd	= "cp ";
	string	line  =   SRC.append(" ");
	line += DST;
	cmd.append(line);

	this->LogToFile("CP(): Intiating copy from the dir", SRC);
	this->LogToFile("CP(): Intiating copy to the dir", DST);
	this->LogToFile("CP(): Initating using command", cmd);

	cout << "Copying from " << SRC << " to " << DST << endl;
	cout << "line = " << line << endl;
	cout << "Final command: " << cmd << endl;
	// system(cmd);
}

bool	ProjectSetup::CopyFiles(void)
{
	string	tempDir	= TEMPDIR;
	string	dirTemp	= tempDir.append(this->Directory);

	cout << "TempDir: " << tempDir << endl;
	cout << "FinalDir: " << dirTemp << endl;
	this->LogToFile("CopyFiles(): Init");

	switch (this->type_iter)
	{
		case 0 :
			this->CP("./setupFiles/c", tempDir);
			break ;
		case 1 :
			this->CP("./setupFiles/ch", tempDir);
			break ;
		case 2 :
			this->CP("./setupFiles/cpp", tempDir);
			break ;
		case 3 :
			this->CP("./setupFiles/cpph", tempDir);
			break ;
		case 4 :
			this->CP("./setupFiles/generic", tempDir);
			break ;
		default :
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
