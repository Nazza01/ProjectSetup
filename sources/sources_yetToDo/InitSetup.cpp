/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitSetup.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:44:39 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 14:23:01 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	initSetup(void)
{
	std::cout << "Welcome to project setup\nI'm going to need a few details "
	<< "before everything is setup" << std::endl;
	if (askDetails() == false)
	{
		logtoFile("askDetails() == false");
		return false;
	}
	else if (askDetails() == true)
	{
		logtoFile("askDetails() == true");
		return true;
	}
	else
	{
		logtoFile("askDetails() function not true or false");
		return true;
	}
}
