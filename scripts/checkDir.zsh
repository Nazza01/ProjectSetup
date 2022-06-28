#!/bin/zsh

read -r "Dir?Which directory would you like this to be in? "

while read -ep "Dir?Which directory would you like this folder to be in? "
	if [ -d "${Dir}" ]; then
		echo "${Dir} already exists - please enter a valid directory path."
	elif [ $Dir == "q" ]; then
		echo "Exiting setup"
		exit
	else
		mkdir -p "${Dir}"
		break
	fi
done
