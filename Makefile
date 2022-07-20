# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:22:59 by Nathanael         #+#    #+#              #
#    Updated: 2022/07/20 10:11:00 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#							Edit this section								   #
NAME		=	ProjectSetup
COMPILER	=	c++
SOURCE_EXT	=	cpp
COMP_STD	=	-std=c++11
COMP_FLAGS	=	-Wall -Wextra -Werror -g
VAL_NAME	=	valtest
# 																			   #
# **************************************************************************** #

#				Progress Bar
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
	ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

#				Directories, Files, Flags and Utilities
SRC_DIR		=	./sources
HDR_DIR		=	./headers
BUI_DIR		=	./build
OBJ_DIR		=	./build/obj
DEP_DIR		=	./build/deps

SOURCES		=	$(shell find $(SRC_DIR) -name '*.$(SOURCE_EXT)')
LOG_FILES	=	$(shell find . -name 'PSLog_*.txt')
OBJECTS		=	$(SOURCES:$(SRC_DIR)/%.$(SOURCE_EXT)=$(BUI_DIR)/%.o)
DEPS		=	$(OBJECTS:$(BUI_DIR)/%.o=$(BUI_DIR)/%.d)

CFLAGS		+=	-$(COMP_STD) $(COMP_FLAGS)
LDFLAGS		+=	
INCLUDES	=	-I $(HDR_DIR)

CLEAN_LST	=	$(NAME) $(BUI_DIR) $(LOG_FILES)

RM			=	rm -rf
MKDIR		=	mkdir -p

# 				 Start Rules

# Default rule to make the program

all: $(NAME)

# Makes the build directory, links the object files to the program
$(NAME): $(OBJECTS)
	@$(ECHO) $@ ready to be run
	@$(MKDIR) $(BUI_DIR)
	@$(COMPILER) $(OBJECTS) $(LDFLAGS) -o $@

# Removes files and folders listed in clean_list
c clean:
	@$(ECHO) Cleaning: $(CLEAN_LST)
	@$(RM) $(CLEAN_LST)

# Removes files and folders listed in clean_list and clears the command window
cc:
	@clear
	@$(ECHO) Cleaning: $(CLEAN_LST)
	@$(RM) $(CLEAN_LST)

# Cleans all files and remakes them
r re: c all

# Uses apple's leaks utility (/usr/bin) to check for leaks upon exit
m mem: all
	@leaks --atExit -- ./$(NAME) > leak_out.txt || true
	@grep -E '(Process) [0-9]{1,}: [0-9]{1,} (leaks)' leak_out.txt
	@grep -E '(ROOT LEAK): <' leak_out.txt || true
	@rm leak_out.txt

v val:
	@$(ECHO) Cleaning any prior containers with the name: $(VAL_NAME)
	@docker stop $(VAL_NAME) || true && docker rm $(VAL_NAME) || true
	@$(ECHO) Creating valgrind docker container named: $(VAL_NAME)
	@docker run --name $(VAL_NAME) -dit livingsavage/42valgrind
	@docker cp $(SRC_DIR) $(VAL_NAME):/usr/code
	@docker cp $(HDR_DIR) $(VAL_NAME):/usr/code
	@docker cp Makefile $(VAL_NAME):/usr/code
	@$(ECHO) Using makefile to create $(NAME)
	@docker exec $(VAL_NAME) make
	@$(ECHO) Using valgrind to output results for $(NAME)
	@docker exec $(VAL_NAME) valgrind ./$(NAME) | grep 'leak'

# Include the dependancies into the compiler so all files can be built
-include $(DEPS)

# Builds the object files from the source directory using the header files and
# 	dependacies, ie: source/main.cpp is linked to object file build/main.o
# From that, the $(NAME) rule can determine all the function definitions inside
# 	each object file
$(BUI_DIR)/%.o : $(SRC_DIR)/%.$(SOURCE_EXT)
	@$(ECHO) Link $< to $@
	@$(MKDIR) $(@D)
	@$(COMPILER) $(CFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@