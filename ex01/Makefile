C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

# ディレクトリ
SRCS_DIR = srcs
OBJS_DIR = objects

# ソースファイル
SRCS_FILES = Contact.cpp \
             PhoneBook.cpp \
             main.cpp

# パスを含むソースファイル
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

# オブジェクトファイル
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.o))

NAME = My_Awesome_PhoneBook

all: $(NAME)

# オブジェクトディレクトリの作成
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# 実行ファイルの作成
$(NAME): $(OBJS_DIR) $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

# オブジェクトファイルの作成
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re