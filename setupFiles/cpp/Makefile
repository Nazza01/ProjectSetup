# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 17:19:09 by Nathanael         #+#    #+#              #
#    Updated: 2022/06/27 17:19:10 by Nathanael        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Make changes here
NAME 		=	a.out

################################################################################
#								DIRECTORIES/FILES							   #
################################################################################
BUILD_DIR	=	./build
HEADERS_DIR	=	./headers
OBJECTS_DIR	=	./objects
SOURCES_DIR	=	./sources

CLEAN		:=	$(BUILD_DIR)
FILE_CLEAN	:=	$(OBJECTS_DIR)

CXX_SOURCES	:=	$(shell find $(SOURCES_DIR) -name '*.cpp')
CXX_OBJECTS	:=	$(CXX_SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)

FINAL_SOURCES:=	$(CXX_SOURCES)
FINAL_OBJECTS:=	$(CXX_OBJECTS)

################################################################################
#								COMPILER/FLAGS								   #
################################################################################
CXX			=	c++
CXX_STAND	=	-std=c++98

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
.DELETE_ON_ERROR: all ca clean fclean r re

.PHONY: all ca clean fclean r re

all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(FINAL_OBJECTS)
	@$(MKDIR) $(BUILD_DIR)
	@$(CXX) $(FINAL_OBJECTS) $(LDFLAGS) -o $@
	@clear
	@printf "Program %s built successfully\n" $@

$(OBJECTS_DIR)/%.o : $(SOURCES_DIR)/%.cpp
	@$(MKDIR) '$(@D)'
	@$(CXX) $(CFLAGS) -c $< -o $@
	@clear
	@printf "Linked %s to: %s\n" $< $@

ca: clean fclean
	@clear
	@printf "Cleaned %s\n" $(FILE_CLEAN) $(CLEAN)

clean:
	@$(RM) $(CLEAN)
	@clear
	@printf "Cleaned: %s\n" $(CLEAN)

fclean:
	@$(RM) $(FILE_CLEAN)
	@clear
	@printf "Cleaned: %s\n" $(FILE_CLEAN)

r:	re

re: fclean clean all
	@clear
	@printf "Cleaned and remade all files!\n"
