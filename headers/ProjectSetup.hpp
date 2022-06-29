/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 23:55:15 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <filesystem>		//C++17 paths

class ProjectSetup
{
public:
	bool						Flag;
	std::string					Type;
	std::string					Name;
	std::string					Directory;
	static const std::string	Type_Headings[5];
	static const std::string	Type_FileList[5];
	static const std::string	setupFiles[8];

	//	AskForDetails.cpp
	void	AskType(void);
	bool	AskDir(void);
	bool	AskName(void);
	bool	AskDetails(void);
	
	//	LogToFile.cpp
	void	LogToFile(std::string msg);
	void	LogToFile(std::string msg, std::string optMsg);

	//	InitSetup.cpp
	void	InitSetup(void);

	//	PreSetup.cpp
	bool	PreSetup(void);
	
	// 	Utils.cpp
	bool	intRangeCheck(int low, int high, std::string x);
	
	//	Default.cpp
	ProjectSetup();
	~ProjectSetup();
};

/**	
 * Type_Headings is used when asking for the type, it is a heading that is chosen
 * when asked for what type of project to be used
**/
const std::string	ProjectSetup::Type_Headings[5] = {
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
const std::string	ProjectSetup::Type_FileList[5] = {
	".gitignore, Makefile, main.c",					//	C
	".gitignore, Makefile, main.c, blank.h"			//	C with Headers
	".gitignore, Makefile, main.cpp",				//	C++
	".gitignore, Makefile, main.cpp, blank.hpp",	//	C++ with Headers
	".gitignore",									//	Generic
};
/**	
 * a_copyFiles is used when copying the files from setupFiles/ to the final dir
 * **/
const std::string	ProjectSetup::setupFiles[8] = {
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