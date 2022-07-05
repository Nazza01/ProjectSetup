/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:47:02 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 10:48:37 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

bool	ProjectSetup::intRangeCheck(int low, int high, string x)
{
	return (low <= stoi(x) && stoi(x) <= high);
}
