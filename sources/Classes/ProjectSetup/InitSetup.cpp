/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitSetup.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:44:39 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 15:35:23 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::InitSetup(void)
{
	std::cout << "Welcome to project setup\nI'm going to need a few details "
	<< "before everything is setup" << std::endl;
	if (this->AskDetails() == false)
	{
		this->LogToFile("askDetails() == false");
		return false;
	}
	else if (this->AskDetails() == true)
	{
		this->LogToFile("askDetails() == true");
		return true;
	}
	else
	{
		this->LogToFile("askDetails() function not true or false");
		return true;
	}
}
