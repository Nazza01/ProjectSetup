/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectSetup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:58 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 14:50:13 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PROJECTSETUP_HPP
#define	PROJECTSETUP_HPP

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <fstream>

class ProjectSetup
{
public:
	int				Type;
	std::string		Name;
	std::string		Directory;
	std::string		askType[5] = {
		"C",
		"C with Headers",
		"C++",
		"C++ with Headers",
		"Generic"
	};
	std::string		askFiles[5] = {
		".gitignore, Makefile, main.c",					//	C
		".gitignore, Makefile, main.c, blank.h"			//	C with Headers
		".gitignore, Makefile, main.cpp",				//	C++
		".gitignore, Makefile, main.cpp, blank.hpp",	//	C++ with Headers
		".gitignore",									//	Generic
	};
	std::string		copyFiles[8] = {
		".gitignore",
		"Makefile",
		"main-itself.c",
		"main-itself.cpp",
		"main-header.c",
		"main-header.cpp",
		"blank.h",
		"blank.hpp",
	};
	void	LogToFile(std::string msg);
	bool	DirSetup();
	bool	InitSetup(void);
	bool	AskDetails(void);
	ProjectSetup();
	~ProjectSetup();
};

#endif