/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogToFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:50:55 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 10:48:38 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

static string	getCurrentDateTime(string s)
{
	time_t		now = time(0);
	struct	tm	tstruct = *localtime(&now);
	char		buf[80];

	if (s == "now")
		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
	else if (s == "date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return string(buf);
}

void	ProjectSetup::LogToFile(string msg)
{
	string		filePath = "SetupLog_"+getCurrentDateTime("date")+".txt";
	string		now = getCurrentDateTime("now");
	ofstream	outfile(filePath.c_str(), ios_base::out | ios_base::app);
	outfile << now << '\t' << msg << '\n';
	outfile.close();
}

void	ProjectSetup::LogToFile(string msg, string optMsg)
{
	string		filePath = "SetupLog_"+getCurrentDateTime("date")+".txt";
	string		now = getCurrentDateTime("now");
	ofstream	outfile(filePath.c_str(), ios_base::out | ios_base::app);
	outfile << now << '\t' << msg << ' ' << optMsg << '\n';
	outfile.close();
}
