/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 16:46:38 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

int	main(void)
{
	ProjectSetup	project;

	project.flag = project.PreSetup();

	if (project.flag == false)
		std::cout << "Temporary directory could not be created, exiting" << std::endl;
		// else if (project.InitSetup() == true)
		// {
			// project.LogToFile("InitSetup() == true");
			// std::cout << "All done, happy coding!" << std::endl;
		// }
	// 	else
	// 	{
	// 		project.LogToFile("InitSetup() didn't return true or false");
	// 		return 1;
	// 	}
	// }
	else if (project.flag == true)
		std::cout << "Temp Dir was created" << std::endl;
	else
	{
		std::cout << "Temp dir in limbo, oops" << std::endl;
	}
	return 0;
}
