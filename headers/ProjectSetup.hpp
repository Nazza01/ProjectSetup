/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 13:53:45 by Nathanael        ###   ########.fr       */
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
	bool						Flag;
	string						Type;
	string						Name;
	string						Directory;
	static const char* const 	Type_Headings[5];
	static const char* const 	Type_FileList[5];
	static const char* const	SetupFiles[8];

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