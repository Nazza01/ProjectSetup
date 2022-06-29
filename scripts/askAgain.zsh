#!/bin/zsh

while true; do
	read -r "Name?What would you like the project to be named?: "
	if [[ $Name == "q" ]]; then
		echo "Exiting program"
		exit
		exit
		exit
	else
		scripts/checkDir.zsh
		scripts/checkType.zsh
		scripts/checkConfirmation.zsh
	fi
done
