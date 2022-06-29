/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitSetup.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:44:39 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 23:05:10 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

void	ProjectSetup::InitSetup(void)
{
	std::cout << "Welcome to project setup\nI'm going to need a few details "
	<< "before everything is setup" << std::endl;
	return (this->AskDetails());
}
