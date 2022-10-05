NAME := philo
#Compiling
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -g -pthread
#Paths
PATH_BUILD		:= ./build
PATH_SRC		:= ./src
PATH_OBJS		:= $(PATH_BUILD)/objs
PATH_LIBFT		:= ./libft
PATH_INCLUDES	:= ./includes
#Getting all the .c files and turning them into .o files
BIN				:= ./$(NAME)
SRCS			:= $(PATH_SRC)/main.c \
					$(PATH_SRC)/init_struct.c \
					$(PATH_SRC)/simulation.c \
					$(PATH_SRC)/utils.c \
					$(PATH_SRC)/life_actions.c \
					$(PATH_SRC)/send_to_die.c \
					$(PATH_SRC)/printer.c

OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))
LIBFT			:= $(PATH_LIBFT)/libft.a

all:$(BIN)

$(BIN): $(OBJ) | $(LIBFT)
		@$(CC) $(CFLAGS) -o $(@) $^ -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDES)

$(PATH_OBJS)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@printf "\033[33m[CREATING ${@F}]\033[0m\n"
		@$(CC) $(CFLAGS) -c $(^) -o $@

$(LIBFT):
		@make -C $(PATH_LIBFT)

$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS)

clean:
		@printf "\033[38;5;1m[REMOVING OBJECTS]\033[0m\n"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@printf "\033[38;5;1m[REMOVING BINARIES]\033[0m\n"
		@rm -rf $(PATH_BUILD) $(NAME)
		@make fclean -C $(PATH_LIBFT)

re: fclean all