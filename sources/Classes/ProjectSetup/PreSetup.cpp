/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PreSetup.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:15 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 16:45:38 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::PreSetup(void)
{
	this->LogToFile("Pre-Setup: Setting up temporary directory");
	this->LogToFile("Pre-Setup: Attempting to make .temp directory");
	mkdir(".temp", 0666);
	return false;
}
