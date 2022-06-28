#!/bin/zsh

TEMPDIR=../.temp

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
			./askAgain.zsh
			break ;
		;;
		*)
			echo "Please answer y to confirm or n to re-enter"
		;;
	esac
done