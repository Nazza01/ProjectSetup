#!/bin/zsh

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
