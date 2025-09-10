CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS_DIR = srcs
OBJS_DIR = objects

SRCS_FILES =	main.cpp \
				Bureaucrat.cpp \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.o))

NAME =   No,you_need_form_28B,not_28C...

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
