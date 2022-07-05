/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 15:12:21 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

const int	m_Type_Headings	= 	5;
const int	m_Type_FileList	=	m_Type_Headings;
const int	m_SetupFiles	=	8;

#define	MAX_TYPE_HEADINGS	5;
#define	MAX_TYPE_FILE_LIST	5;
#define	MAX_SETUP_FILES	8;

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
	bool						Flag;
	string						Type;
	string						Name;
	string						Directory;
	static const char* const 	Type_Headings[m_Type_Headings];
	static const char* const 	Type_FileList[m_Type_FileList];
	static const char* const	SetupFiles[m_SetupFiles];
	int							type_iter;

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


#endif