/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:40 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 23:00:47 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

int	main(void)
{
	ProjectSetup	project;

	project.Flag = project.PreSetup();

	if (project.Flag == EXIT_SUCCESS)
	{
		std::cout << "Temp Dir was created" << std::endl;
	}
	else if (project.Flag == EXIT_FAILURE)
	{
		std::cout << "Temp Dir failed to be created" << std::endl;
	}
	else
	{
		std::cout << "Temp dir was none of: failed or successfull, we will never know" << std::endl;
	}
	return 0;
}
