#!/bin/zsh

TEMPDIR=../.temp
FINAL_DIR=$TEMPDIR/$Dir/$Name

mkdir -p $FINAL_DIR/sources
while true; do
	echo "Which type of project are you developing for?"
	echo "1: C\t\t-\t.gitignore, Makefile, main.c"
	echo "2: C + header\t-\t.gitignore, Makefile, main.c, blank.h"
	echo "3: CPP\t\t-\t.gitignore, Makefile, main.cpp"
	echo "4: CPP + header\t-\t.gitignore, Makefile, main.cpp, blank.hpp"
	echo "5: Generic\t\t-\t.gitignore"
	read -r "Type?Choice: "
	case $Type in
	[1])
		cp ../setupFiles/.gitignore $FINAL_DIR/.gitignore
		cp ../setupFiles/Makefile $FINAL_DIR/Makefile
		cp ../setupFiles/C/sources/main-itself.c $FINAL_DIR/sources/main.c
		break ;
	;;
	[2])
		mkdir -p $FINAL_DIR/headers
		cp ../setupFiles/.gitignore $FINAL_DIR/.gitignore
		cp ../setupFiles/C/Makefile $FINAL_DIR/Makefile
		cp ../setupFiles/C/headers/blank.h $FINAL_DIR/headers/blank.h
		cp ../setupFiles/C/sources/main-header.c $FINAL_DIR/sources/main.c
		break ;
	;;
	[3])
		cp ../setupFiles/CPP/.gitignore $FINAL_DIR/.gitignore
		cp ../setupFiles/CPP/Makefile $FINAL_DIR/Makefile
		cp ../setupFiles/CPP/sources/main-itself.cpp $FINAL_DIR/sources/main.cpp
		break ;
	;;
	[4])
		mkdir -p $FINAL_DIR/headers
		cp ../setupFiles/CPP/.gitignore $FINAL_DIR/.gitignore
		cp ../setupFiles/CPP/Makefile $FINAL_DIR/Makefile
		cp ../setupFiles/CPP/headers/blank.hpp $FINAL_DIR/headers/blank.hpp
		cp ../setupFiles/CPP/sources/main-header.cpp $FINAL_DIR/sources/main.cpp
		break ;
	;;
	[5])
		cp ../setupFiles/Generic/.gitignore $TEMPDIR/$Dir/$Name/.gitignore
		break ;
	;;
	*)
		echo $Type "is not a valid choice, please try again"
	;;
	esac
done
