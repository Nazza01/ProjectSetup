#!/bin/bash

TempDir=.temp

echo -n "Pre-Setup: "
echo -n "Checking additional script permissions"
for files in scripts/*; do
	if [ -x "$files" ]; then
		echo -n "."
	else
		chmod +x "$files"
		echo -n "..."
	fi
done
echo "done"

echo -n "Pre-Setup: "
echo -n "Setting up temporary directory"
echo -n "..."
mkdir -p .temp/
echo "done"

printf "\nWelcome to project setup!\n"
printf "I'm going to need a few details before everything is setup\n"
./scripts/askAgain.zsh

printf "Okay, just to confirm:\n"
printf "\tProject %s" "$Name" "will be created in the following directory %s" "$Dir" 
printf " and will be a "
case $Type in
	[1]) echo -n "C"; ;;
	[2]) echo -n "C (with headers)"; ;;
	[3]) echo -n "C++"; ;;
	[4]) echo -n "C++ (with headers)"; ;;
	[5]) echo -n "Generic"; ;;
	*) echo "custom" $Type; ;;
esac
echo " project type"
./scripts/checkConfirmation.zsh

echo "Creating and Copying files"

echo "Current Directory Structure"
echo $TempDir/$Dir
echo -n " |- "
ls $TempDir/$Dir

echo -n "One last thing, would you like to initialise this directory" $Dir "as a "
echo "git repository?"

./scripts/gitInit.zsh

echo "Alrighty, all done! Happy coding :)"

while true; do
	read -r "cln?Clean dir? "
	case $Type in
		[Yy]) rm -r $TempDir/*; ;;
		[Nn]) echo "Okay cool, goodluck!"; ;;
		*) echo "Please try again"; ;;
	esac
done

# echo "Moving files"
# ./scripts/moveFiles.zsh
