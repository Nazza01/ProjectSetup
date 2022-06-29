/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckEmpty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:02:44 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 23:05:12 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::CheckEmpty(std::string str)
{
	if (str != "" || str != "\0")
	{
		this->LogToFile("checkEmpty(str): not empty string");
		return EXIT_SUCCESS;
	}
	else
	{
		this->LogToFile("checkEmpty(str): string is empty");
		return EXIT_FAILURE;
	}
}
