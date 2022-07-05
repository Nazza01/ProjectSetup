/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 11:06:34 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <array>

using	std::cout;
using	std::cin;
using	std::endl;
using	std::string;
using	std::ios_base;
using	std::getline;
using	std::ofstream;
using	std::array;

class ProjectSetup
{
public:
	bool	Flag;
	string	Type;
	string	Name;
	string	Directory;
	static	array<string, 5> const Type_Headings;
	static	array<string, 5> const Type_FileList;
	static	array<string, 8> const SetupFiles;

	//	AskForDetails.cpp
	bool	AskType(void);
	bool	AskDir(void);
	bool	AskName(void);
	bool	AskAgain(void);
	
	//	Default.cpp
	ProjectSetup();
	~ProjectSetup();

	//	PreSetup.cpp
	bool	PreSetup(void);

	//	LogToFile.cpp
	void	LogToFile(string msg);
	void	LogToFile(string msg, string optMsg);

	//	InitSetup.cpp
	void	InitSetup(void);

	
	// 	Utils.cpp
	bool	intRangeCheck(int low, int high, string x);
	
};

array<string, 5> const ProjectSetup::Type_Headings {
	"C",
	"C with Headers",
	"C++",
	"C++ with Headers",
	"Generic"
};

/**	
 * Type_FileList is used with the above Type_Headings to list out each file that
 * will be copied over when setting up all the files
**/
array<string, 5> const	ProjectSetup::Type_FileList = {
	".gitignore, Makefile, main.c",					//	C
	".gitignore, Makefile, main.c, blank.h"			//	C with Headers
	".gitignore, Makefile, main.cpp",				//	C++
	".gitignore, Makefile, main.cpp, blank.hpp",	//	C++ with Headers
	".gitignore",									//	Generic
};

/**	
 * a_copyFiles is used when copying the files from setupFiles/ to the final dir
 * **/
array<string, 8> const	ProjectSetup::SetupFiles = {
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


#endif