/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 12:09:54 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

int	main(void)
{
	std::cout << "PreSetup" << std::endl;
	std::cout << "Setting up temporary directory" << std::endl;
	if (DirSetup() == false)
		std::cout << "Temporary directory not setup" << std::endl;
	else if (DirSetup() == true)
	{
		if (InitSetup() == false)
			std::cout << "Initial setup failed" << std::endl;
		else if (InitSetup() == true)
		{
			std::cout << "Initial setup complete" << std::endl;
			std::cout << "All done, happy coding!" << std::endl;
		}
		else
			std::cout << "InitSetup didn't return true or false." << std::endl;
			return 1;
	}
	else
		LogtoFile("Error: DirSetup() not working");
	return 0;
}
