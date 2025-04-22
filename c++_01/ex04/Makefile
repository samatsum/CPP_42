C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_DIR = srcs
OBJS_DIR = objects

SRCS_FILES =	main.cpp\

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.o))

NAME = Sed_is_for_losers

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
