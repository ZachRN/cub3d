NAME = cub3d
BUILD_DIR = build
VPATH := $(subst $(" "),:,$(shell find srcs -type d))
SRCS += $(wildcard srcs/*.c srcs/*/*.c) 
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))
HEADER_FILES := $(addprefix -I,$(shell find includes -type d -print))
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
CC = gcc
#Makefile will need to include additonal things for compiling with the
#graphical library, i pulled my minishell makefile, not fractol
all: build_dir $(NAME)

$(NAME): $(OBJ_FILES)
	@echo Assembling $(NAME)
	@$(CC) -o $@ $^ $(CFLAGS)
	@echo $(NAME) has been made!

$(BUILD_DIR)/%.o: %.c
	@$(CC) $(HEADER_FILES) -c $(CFLAGS) -o $@ $<

build_dir:
	clear
	@if [ -d "./$(BUILD_DIR)" ]; then \
	echo "Build Directory Already Exists"; \
	else \
	mkdir -p $(BUILD_DIR); \
	fi

clean:
	clear
	@echo Cleaning all object files 
	@ rm -f $(BUILD_DIR)/*.o
	@echo Removing Build Directory
	@if [ -d "./$(BUILD_DIR)" ]; then \
	rmdir $(BUILD_DIR); fi

fclean: clean
	@echo Removing $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re build_dir