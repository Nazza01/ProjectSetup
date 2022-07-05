/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:06:53 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 13:54:00 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

const char* const ProjectSetup::Type_Headings[5] = 
{
	"C", 
	"C .h",
	"C++",
	"C++ .h",
	"Generic"
};

const char* const ProjectSetup::Type_FileList[5] =
{
	".gitignore, Makefile, main.c",					//	C
	".gitignore, Makefile, main.c, blank.h",		//	C with Headers
	".gitignore, Makefile, main.cpp",				//	C++
	".gitignore, Makefile, main.cpp, blank.hpp",	//	C++ with Headers
	".gitignore",									//	Generic
};

/**	
 * a_copyFiles is used when copying the files from setupFiles/ to the final dir
 * **/
const char* const ProjectSetup::SetupFiles[8] = 
{
	".gitignore",									//	.gitignore				[C & C++ Versions]
	"Makefile",										//	Makefile				[C & C++ Versions]
	"main-itself.c",								//	C Main					[C - main hello world - no includes]
	"main-itself.cpp",								//	C++ Main				[C++ - main hello world - no includes]
	"main-header.c",								//	C Main					[C - main hello world - header includes]
	"main-header.cpp",								//	C++ Main				[C++ - main hello world - header includes]
	"blank.h",										//	C Header				[C Style Header - Basic ifndef with includes for printf]
	"blank.hpp",									//	C++ Header				[C++ Style Header - Basic ifndef with includes for cout]
	
	/*
Todo:	Still neeed to create these files and implement them in the Type_Headings & Type_FileList

	"struct.h",										//	C Header				[C Style Header with struct definitions confirming to norminette rules]
	"main-struct.c".								//	C Main 					[C - with struct includes]
	
	"class.h",										//	C++ Class Definition	[C++ - includes default class defintions]
	"class.hpp",									//	C++ Class Implements	[C++ - includes default header implementations]
	"main-class.cpp",								//	C++ Main				[C++ - with class includes]
	*/
};

ProjectSetup::ProjectSetup(void)
{
	this->LogToFile("------------------ PROJECT_SETUP ------------------");
	this->LogToFile("ProjectSetup::ProjectSetup(void): Constructor called");
}

ProjectSetup::~ProjectSetup(void)
{
	this->LogToFile("ProjectSetup::ProjectSetup(void): Destructor called");
	// this->LogToFile("ProjectSetup::ProjectSetup(void): Removing .temp/ directory");
	// system("rmdir .temp/");
	// system("rm SetupLog_*.txt");
}
