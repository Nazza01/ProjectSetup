/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:54:13 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

int	main(void)
{
	ProjectSetup	project;

	project.LogToFile("Pre-Setup: Setting up temporary directory");
	if (project.DirSetup() == false)
		project.LogToFile("Pre-Setup: Temp Directory Setup Failed");
	else if (project.DirSetup() == true)
	{
		project.LogToFile("Dirsetup == true");
	// 	if (project.InitSetup() == false)
	// 		project.LogToFile("InitSetup == false");
	// 	else if (project.InitSetup() == true)
	// 	{
	// 		project.LogToFile("InitSetup() == true");
	// 		std::cout << "All done, happy coding!" << std::endl;
	// 	}
	// 	else
	// 	{
	// 		project.LogToFile("InitSetup() didn't return true or false");
	// 		return 1;
	// 	}
	}
	else
		project.LogToFile("Error: DirSetup() not working");
	return 0;
}
