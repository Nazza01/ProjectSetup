/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PreSetup.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:15 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/06 09:45:46 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::PreSetup(void)
{
	int var;
	this->LogToFile("Pre-Setup: Setting up temporary directory");
	this->LogToFile("Pre-Setup: Attempting to make .temp directory");
	var = mkdir(".temp", 0777);

	if (var == 0)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}
