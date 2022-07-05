/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:06:53 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 16:28:15 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

/**
 * update the global variable in header file: m_Type_Headings when anything is added here
**/
const char* const ProjectSetup::Type_Headings[m_Type_Headings] = 
{
	"C", 
	"C .h",
	"C++",
	"C++ .h",
	"Generic"
};

/**
 * update the global variable in header file: m_Type_Headings when anything is added here
**/
const char* const ProjectSetup::Type_FileList[m_Type_FileList] =
{
	".gitignore, Makefile, main.c",					//	C
	".gitignore, Makefile, main.c, blank.h",		//	C with Headers
	".gitignore, Makefile, main.cpp",				//	C++
	".gitignore, Makefile, main.cpp, blank.hpp",	//	C++ with Headers
	".gitignore",									//	Generic
};

/**
 * @brief 
	"struct.h",										//	C Header				[C Style Header with struct definitions confirming to norminette rules]
	"main-struct.c".								//	C Main 					[C - with struct includes]
	"class.h",										//	C++ Class Definition	[C++ - includes default class defintions]
	"class.hpp",									//	C++ Class Implements	[C++ - includes default header implementations]
	"main-class.cpp",								//	C++ Main				[C++ - with class includes]
	
 * **/

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
