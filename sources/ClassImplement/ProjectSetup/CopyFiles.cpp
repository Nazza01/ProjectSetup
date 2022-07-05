/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyFiles.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:55:32 by Nathanael         #+#    #+#             */
/*   Updated: 2022/07/05 16:45:06 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjectSetup.hpp"

//From
//  https://stackoverflow.com/questions/54498643/i-can-not-make-a-copy-of-all-the-files-inside-a-folder-with-c
static void rmvPath(string &startingPath, string &fullPath) 
{
    // look for starting path in the fullpath
    int index = fullPath.find(startingPath);

    if (index != string::npos)
    {
        fullPath = fullPath.erase(0, startingPath.length());
    }
}

void	ProjectSetup::CP(std::string SRC, std::string DST)
{
// create dir if doesn't exist
    fs::path dir = DST;
    fs::create_directory(dir);

    // loop through directory
    for (auto& p : fs::recursive_directory_iterator(SRC))
    {
        // convert path to string
        fs::path path = p.path();
        string pathString = path.string();

        // remove starting dir from path
        rmvPath(SRC, pathString);

        // copy file
        fs::path newPath = DST + pathString;
        fs::path oldPath = SRC + pathString;


        try {
            // create file
            fs::copy_file(oldPath, newPath, fs::copy_options::overwrite_existing);
        }
        catch (fs::filesystem_error& e) {
            // create dir
            fs::create_directory(newPath);
        }
    }
}

bool	ProjectSetup::CopyFiles(void)
{
	this->LogToFile("CopyFiles(): Init");
	switch (this->type_iter)
	{
		case 0 :
			this->CP("./setupFiles/c", "./temp");
			break ;
		case 1 :
			this->CP("./setupFiles/ch", "./temp");
			break ;
		case 2 :
			this->CP("./setupFiles/cpp", "./temp");
			break ;
		case 3 :
			this->CP("./setupFiles/cpph", "./temp");
			break ;
		case 4 :
			this->CP("./setupFiles/generic", "./temp");
			break ;
		default :
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
