#!/bin/zsh

read -r "Name?What would you like the project to be named?: "
read -r "Dir?Which directory would you like this to be in?: "
read -r "Type?Which type of project are you developing for? (1: C, 2: CPP or 3 for Generic): "
./checkType.zsh
# $canAccess		# <-- check dir access & if it exists
./checkConfirmation.zsh
