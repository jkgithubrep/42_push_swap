# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2019/04/18 17:36:06 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- VARIABLES -----

NC =            \x1b[0m
OK_COLOR =      \x1b[32;01m
ERR_COLOR =     \x1b[31;01m
WARN_COLOR =    \x1b[34;01m
QUIET :=        @
ECHO :=         @echo
ifneq ($(QUIET),@)
ECHO :=         @true
endif
SHELL =         /bin/sh
MAKEFLAGS +=    --warn-undefined-variables
NAME_1 =        checker
NAME_2 =        push_swap
NAME = 			$(NAME_1) $(NAME_2)
SRC_PATH =      srcs
INCLUDE_PATH =  includes
OBJ_PATH =      .obj
RM =            rm -f
RMDIR =         rmdir
AR =            ar
ARFLAGS =       -rcs
CC =            gcc
CFLAGS =        -g3 -Werror -Wall -Wextra
LFT_PATH = 		libft
LFT_INC_PATH =  $(LFT_PATH)/includes
LFT_NAME =      libft.a
LFT =           $(LFT_PATH)/$(LFT_NAME)
LFT_FLAGS =     -L$(LFT_PATH) -lft
CPPFLAGS =      -I$(INCLUDE_PATH) -I$(LFT_INC_PATH)
DEPFLAGS =      -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.d
COMPILE.c =     $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
POSTCOMPILE =   touch $@
SRC_NAME_1 =    checker
SRC_NAME_2 =    push_swap algo algo_2 algo_utils insertion_sort
SRC_NAME_1_2 =  utils input parser list_utils print_utils actions push \
				rotate reverse_rotate swap list_utils_2 list_utils_3
SRC_NAME = 		$(SRC_NAME_1_2) $(SRC_NAME_1) $(SRC_NAME_2)
SRC_1 =         $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME_1)))
SRC_2 =         $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME_2)))
SRC_1_2 =		$(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME_1_2)))
SRC =           $(SRC_1) $(SRC_2) $(SRC_1_2)
OBJ_1 =         $(addprefix $(OBJ_PATH)/, $(SRC_1:.c=.o))
OBJ_2 =         $(addprefix $(OBJ_PATH)/, $(SRC_2:.c=.o))
OBJ_1_2 =       $(addprefix $(OBJ_PATH)/, $(SRC_1_2:.c=.o))
OBJ =           $(OBJ_1) $(OBJ_2) $(OBJ_1_2)
DEP =           $(addprefix $(OBJ_PATH)/, $(SRC:.c=.d))
OBJ_TREE =      $(shell find $(OBJ_PATH) -type d -print | sort -r \
				2> /dev/null)

# If the first argument is "test_checker" or "test_pushswap"...
#ifeq (test_checker, $(firstword $(MAKECMDGOALS)))
ifneq (,$(filter $(firstword $(MAKECMDGOALS)),test_checker test_pushswap))
  # use the rest as arguments
  TEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(TEST_ARGS):;@:)
endif

.SUFFIXES:
.SUFFIXES: .c .o .h

# ----- RULES -----

.PHONY: all
all: $(NAME)

.PRECIOUS: $(OBJ_PATH)%/. $(OBJ_PATH)/. 
$(OBJ_PATH)/. $(OBJ_PATH)%/.: 
	$(ECHO) "Making directory $(WARN_COLOR)$@$(NC)..."
	$(QUIET) mkdir -p $@

$(OBJ_PATH)/%.d: ;

.SECONDEXPANSION:

$(OBJ): $(OBJ_PATH)/%.o: %.c $(OBJ_PATH)/%.d | $$(@D)/.
	$(ECHO) "Compiling $(WARN_COLOR)$<$(NC)..."
	$(QUIET) $(COMPILE.c) $< -o $@
	$(QUIET) $(POSTCOMPILE)

$(LFT): force_rule
	$(ECHO) "Compiling $(WARN_COLOR)$(LFT)$(NC) if necessary..."
	$(QUIET) make -C $(LFT_PATH)

force_rule:

$(NAME_1): $(OBJ_1) $(OBJ_1_2) $(LFT)
	$(ECHO) "Compiling $(WARN_COLOR)$@$(NC)..."
	$(QUIET) $(CC) $(CFLAGS) $(CPPFLAGS) $(LFT_FLAGS) $(OBJ_1) $(OBJ_1_2) -o $@

$(NAME_2): $(OBJ_2) $(OBJ_1_2) $(LFT)
	$(ECHO) "Compiling $(WARN_COLOR)$@$(NC)..."
	$(QUIET) $(CC) $(CFLAGS) $(CPPFLAGS) $(LFT_FLAGS) $(OBJ_2) $(OBJ_1_2) -o $@

.PHONY: test_checker
test_checker: $(NAME_1)
	$(ECHO) "-----------------"
	$(ECHO) "Launching tests for $(WARN_COLOR)$(NAME_1)$(NC)...\n"
	$(QUIET) ./$(NAME_1) $(TEST_ARGS)

.PHONY: test_pushswap
test_pushswap: $(NAME_2)
	$(ECHO) "-----------------"
	$(ECHO) "Launching tests for $(WARN_COLOR)$(NAME_2)$(NC)...\n"
	$(QUIET) ./$(NAME_2) $(TEST_ARGS)


.PHONY: norminette
norminette:
	$(ECHO) "$(WARN_COLOR)Checking norminette on .h files...$(NC)"
	$(QUIET) norminette $(INCLUDE_PATH)
	$(ECHO) "$(WARN_COLOR)Checking norminette on .c files...$(NC)"
	$(QUIET) norminette $(SRC_PATH)
	$(ECHO) "$(WARN_COLOR)Checking norminette on libft files...$(NC)"
	$(QUIET) norminette $(LFT_PATH)/srcs
	$(QUIET) norminette $(LFT_PATH)/includes

.PHONY: clean
clean:
	$(ECHO) "Cleaning object files..."
	$(QUIET) $(RM) $(OBJ)
	$(ECHO) "Cleaning dependency files..."
	$(QUIET) $(RM) $(DEP)
	$(ECHO) "Cleaning obj tree..."
	$(QUIET) echo $(OBJ_TREE) | xargs $(RMDIR) 2> /dev/null || true
	@if [ -d $(OBJ_PATH) ]; \
		then echo "$(ERR_COLOR)-> Could not clean obj directory.$(NC)"; \
		else echo "$(OK_COLOR)-> Obj directory succesfully cleaned.$(NC)"; fi

.PHONY: fclean
fclean: clean
	$(ECHO) "Cleaning $(NAME_1)..."
	$(QUIET) $(RM) $(NAME_1)
	@if [ -f $(NAME_1) ]; \
		then echo "$(ERR_COLOR)-> Could not clean $(NAME_1).$(NC)"; \
		else echo "$(OK_COLOR)-> $(NAME_1) succesfully cleaned.$(NC)"; fi
	$(ECHO) "Cleaning $(NAME_2)..."
	$(QUIET) $(RM) $(NAME_2)
	@if [ -f $(NAME_2) ]; \
		then echo "$(ERR_COLOR)-> Could not clean $(NAME_2).$(NC)"; \
		else echo "$(OK_COLOR)-> $(NAME_2) succesfully cleaned.$(NC)"; fi

.PHONY: re
re: fclean all

# ----- INCLUDES -----

-include $(DEP)
