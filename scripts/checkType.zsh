#!/bin/zsh

TempDir=../.temp
FinalDir=$TempDir/$Dir/$Name

mkdir -p $FINAL_DIR/sources
while true; do
	echo "Which type of project are you developing for?"
	echo "1: C\t\t-\t.gitignore, Makefile, main.c"
	echo "2: C + header\t-\t.gitignore, Makefile, main.c, blank.h"
	echo "3: CPP\t\t-\t.gitignore, Makefile, main.cpp"
	echo "4: CPP + header\t-\t.gitignore, Makefile, main.cpp, blank.hpp"
	echo "5: Generic\t-\t.gitignore"
	read -r "Type?Choice: "
	case $Type in
	[1])
		cp ../setupFiles/.gitignore $FinalDir/.gitignore
		cp ../setupFiles/Makefile $FinalDir/Makefile
		cp ../setupFiles/C/sources/main-itself.c $FinalDir/sources/main.c
		break ;
	;;
	[2])
		mkdir -p $FinalDir/headers
		cp ../setupFiles/.gitignore $FinalDir/.gitignore
		cp ../setupFiles/C/Makefile $FinalDir/Makefile
		cp ../setupFiles/C/headers/blank.h $FinalDir/headers/blank.h
		cp ../setupFiles/C/sources/main-header.c $FinalDir/sources/main.c
		break ;
	;;
	[3])
		cp ../setupFiles/CPP/.gitignore $FinalDir/.gitignore
		cp ../setupFiles/CPP/Makefile $FinalDir/Makefile
		cp ../setupFiles/CPP/sources/main-itself.cpp $FinalDir/sources/main.cpp
		break ;
	;;
	[4])
		mkdir -p $FinalDir/headers
		cp ../setupFiles/CPP/.gitignore $FinalDir/.gitignore
		cp ../setupFiles/CPP/Makefile $FinalDir/Makefile
		cp ../setupFiles/CPP/headers/blank.hpp $FinalDir/headers/blank.hpp
		cp ../setupFiles/CPP/sources/main-header.cpp $FinalDir/sources/main.cpp
		break ;
	;;
	[5])
		cp ../setupFiles/Generic/.gitignore $FinalDir/.gitignore
		break ;
	;;
	*)
		echo $Type "is not a valid choice, please try again"
	;;
	esac
done
