#!/bin/zsh

TEMPDIR=.temp
mkdir -p .temp/

function gitInit() {
	while true; do
		read -r "gitConf?Y or N to confirm "
		case $gitConf in
			[Yy])
				git init $Dir
				git add $Dir/.gitignore
				git add $Dir
			;;
			[Nn])
				echo "Okay no worries! All done!"
				break ;
			;;
			*)
				echo $gitConf "is not a valid choice, please try again"
			;;
		esac
	done

}

function checkType() {
	mkdir -p $TEMPDIR/$Dir/$Name/sources
	mkdir -p $TEMPDIR/$Dir/$Name/headers
	while true; do
		case $Type in
		[1])
			cp setupFiles/C/main.c $TEMPDIR/$Dir/$Name/sources/main.c
			cp setupFiles/C/blank.h $TEMPDIR/$Dir/$Name/headers/blank.h
			cp setupFiles/C/Makefile $TEMPDIR/$Dir/$Name/Makefile
			cp setupFiles/C/.gitignore $TEMPDIR/$Dir/$Name/.gitignore
			break ;
		;;
		[2])
			cp setupFiles/CPP/main.cpp $TEMPDIR/$Dir/$Name/sources/main.cpp
			cp setupFiles/CPP/blank.hpp $TEMPDIR/$Dir/$Name/headers/blank.h
			cp setupFiles/CPP/Makefile $TEMPDIR/$Dir/$Name/Makefile
			cp setupFiles/CPP/.gitignore $TEMPDIR/$Dir/$Name/.gitignore
			break ;
		;;
		[3])
			cp setupFiles/Generic/.gitignore $TEMPDIR/$Dir/$Name/.gitignore
			break ;
		;;
		*)
			echo $Type "is not a valid choice, please try again"
		;;
		esac
	done
}

function askAgain() {
	read -r "Name?What would you like the project to be named?: "
	read -r "Dir?Which directory would you like this to be in?: "
	read -r "Type?Which type of project are you developing for? (1: C, 2: CPP or 3 for Generic): "
	checkType
	# $canAccess		# <-- check dir access & if it exists
}

function checkConfirmation() {
	while true; do
		read -r "choice?Does that sound correct? (y/n) "
		case $choice in
			[y])
				echo "Great, lets proceed"
				break ;
			;;
			[n])
				echo "Okay, lets try again"
				echo "Removing old files"
				rm -r $TEMPDIR/*
				askAgain
				break ;
			;;
			*)
				echo "Please answer y to confirm or n to re-enter"
			;;
		esac
	done
}

echo "Welcome to project setup!\n"
echo "I'm going to need a few details before everything is setup\n"
read -r "Name?What would you like the project to be named: "
read -r "Dir?Which directory would you like this to be in? "
read -r "Type?Which type of project are you developing for? (1: C, 2: CPP or 3 for Generic): "
checkType
# I need to get the directory and then checkType as then it can get the path to copy files over
# At the moment no such file or dir as the vars haven't been passed

echo "Okay, just to confirm: "
echo -n "\tProject" $Name "will be created in the following directory" $Dir
echo -n " and will be a "
case $Type in
	[1]) echo -n "C"; ;;
	[2]) echo -n "C++"; ;;
	[3]) echo -n "generic"; ;;
	*) echo "custom" $Type; ;;
esac
echo " project type"
checkConfirmation

echo "Creating and Copying files"

echo "Current Directory Structure"
echo $TEMPDIR/$Dir
echo " | "
echo -n " |- "
ls $TEMPDIR/$Dir

echo -n "One last thing, would you like to initialise this directory" $Dir "as a "
echo "git repository?"

gitInit


echo "Alrighty, all done! Happy coding :)"
