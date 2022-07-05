/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 16:43:40 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

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
	bool						Flag;
	string						Type;
	string						Name;
	string						Directory;
	static const char* const 	Type_Headings[m_Type_Headings];
	static const char* const 	Type_FileList[m_Type_FileList];
	int							type_iter;

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