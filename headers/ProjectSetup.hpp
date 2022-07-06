/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/06 11:04:52 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

#define	LOG_NAME	"PSLog_"
#define	TEMPDIR		"./.temp"

const int	m_Type_Headings	= 	5;
const int	m_Type_FileList	=	m_Type_Headings;

#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <sys/stat.h>
#include <iostream>
#include <array>
#include <fstream>
#include <cstdlib>

#include <filesystem>
// namespace fs = std::filesystem;		// May not work, if so, comment the above namespace out and uncomment this one

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

using	std::cout;
using	std::cin;
using	std::endl;
using	std::string;
using	std::ios_base;
using	std::getline;
using	std::ifstream;
using	std::ofstream;
using	std::array;
using	std::ios;

 
class ProjectSetup
{
public:
	string						Type;											//	The Type of project							(./SetupFiles/<type>)
	string						Name;											//	The Name of the project						(././temp/Name -> Moves to -> <FinalDir>)
	string						Directory;										//	The Temp Directory location					(./.temp/<dir>)
	string						FinalDir;										//	The Final Directory to move all files to	(<FinalDir>/<folderStructure>)
	static const char* const 	Type_Headings[m_Type_Headings];					//	Listing of the headings used
	static const char* const 	Type_FileList[m_Type_FileList];					//	Listing of the files to be moved according to the headings
	int							type_iter;										//	Iter selection of the file list

	//	AskForDetails.cpp
	bool	AskType(void);
	bool	AskDir(void);
	bool	AskName(void);
	bool	AskAgain(void);
	
	//	CopyFiles.cpp
	void	CP(std::string SRC, std::string DST);
	bool	CopyFiles(void);

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
#endif