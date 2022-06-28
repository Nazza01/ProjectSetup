#!/bin/zsh

TEMPDIR=.temp
mkdir -p .temp/

echo "Testing Script Permissions"
for files in scripts/*; do
	if [ -x $files ]; then
		echo -n $files "..."
		echo "Done"
	else
		echo -n "Setting permissions for:" $files
		chmod +x $files
		echo " ...Done"
	fi
done

echo "\nWelcome to project setup!\n"
echo "I'm going to need a few details before everything is setup\n"
read -r "Name?What would you like the project to be named: "
read -r "Dir?Which directory would you like this to be in? "
./scripts/checkType.zsh
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
./scripts/checkConfirmation.zsh

echo "Creating and Copying files"

echo "Current Directory Structure"
echo $TEMPDIR/$Dir
echo -n " |- "
ls $TEMPDIR/$Dir

echo -n "One last thing, would you like to initialise this directory" $Dir "as a "
echo "git repository?"

./scripts/gitInit.zsh

echo "Alrighty, all done! Happy coding :)"

while true; do
	read -r "cln?Clean dir? "
	case $Type in
		[Yy]) rm -r $TEMPDIR/*; ;;
		[Nn]) echo "Okay cool, goodluck!"; ;;
		*) echo "Please try again"; ;;
	esac
done
