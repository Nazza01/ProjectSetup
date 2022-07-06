# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 20:23:35 by Nathanael         #+#    #+#              #
#    Updated: 2022/07/06 09:24:24 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Make changes here
NAME 		=	ProjectSetup


################################################################################
#								PROGRESS BAR - DONT TOUCH					   #
################################################################################
ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
		@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
	ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

################################################################################
#								DIRECTORIES/FILES							   #
################################################################################
HEADERS_DIR	=	./headers
OBJECTS_DIR	=	./objects
SOURCES_DIR	=	./sources

LOGS		=	$(shell find . -name 'SetupLog_**.txt')

CLEAN		:=	$(NAME)
FILE_CLEAN	:=	$(OBJECTS_DIR)

CXX_SOURCES	:=	$(shell find $(SOURCES_DIR) -name '*.cpp')
CXX_OBJECTS	:=	$(CXX_SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)

FINAL_SOURCES:=	$(CXX_SOURCES)
FINAL_OBJECTS:=	$(CXX_OBJECTS)

################################################################################
#								COMPILER/FLAGS								   #
################################################################################
CXX			=	g++
CXX_STAND	=	-std=c++17

CDEBUG		=	-g

COMMON_FLAGS=	-Wall -Wextra -Werror -I $(HEADERS_DIR)

CFLAGS		=	$(COMMON_FLAGS) $(CDEBUG)
LDFLAGS		=	$(COMMON_FLAGS) $(CDEBUG)

################################################################################
#								EXTERNAL UTILITIES							   #
################################################################################
RM			=	rm -rf
MKDIR		=	mkdir -p
CP			=	cp

################################################################################
#								COMMANDS									   #
################################################################################
.DELETE_ON_ERROR:
.PHONY:

all: $(NAME)

$(NAME): $(FINAL_OBJECTS)
	@$(CXX) $(FINAL_OBJECTS) $(LDFLAGS) -o $@
	@sleep 0.1
	@$(ECHO) $(NAME) Created

$(OBJECTS_DIR)/%.o : $(SOURCES_DIR)/%.cpp
	@$(MKDIR) '$(@D)'
	@$(CXX) $(CFLAGS) -c $< -o $@
	@sleep 0.1
	@$(ECHO) Linking $< to $@

ca: clean fclean cl
	@sleep 0.1
	@$(ECHO) $(CLEAN) $(FILE_CLEAN) $(LOGS) all cleaned

clean:
	@$(RM) $(CLEAN)
	@sleep 0.1
	@$(ECHO) $(CLEAN) cleaned

fclean:
	@$(RM) $(FILE_CLEAN)
	@sleep 0.1
	@$(ECHO) $(FILE_CLEAN) cleaned

cl:
	@$(RM) $(LOGS)
	@sleep 0.1
	@$(ECHO) $(LOGS) cleaned

r:	re
	@sleep 0.1
	@$(ECHO) Cleaning and Re-Compiling Files

re: ca all
	@sleep 0.1
	@$(ECHO) Cleaning and Re-Compiling Files

endif