/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogToFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:50:55 by Nathanael         #+#    #+#             */
/*   Updated: 2022/06/29 12:07:54 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

static std::string	getCurrentDateTime(std::string s)
{
	time_t		now = time(0);
	struct	tm	tstruct;
	char		buf[80];
	tstruct = *localtime(&now);
	if (s == "now")
		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
	else if(s=="date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return std::string(buf);
}

void			LogToFile(std::string msg)
{
	std::string		filePath	=	"SetupLog_"+getCurrentDateTime("date")+".txt";
	std::string		now			=	getCurrentDateTime("now");
	std::ofstream	outfile(filePath.c_str(), std::ios_base::out | std::ios_base::app);
	outfile << now << '\t' << msg << '\n';
	outfile.close();
}
