/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:49:29 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 21:37:25 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

ProjectSetup::ProjectSetup(void)
{
	this->LogToFile("------------------ PROJECT_SETUP ------------------");
	this->LogToFile("ProjectSetup::ProjectSetup(void): Constructor called");
}