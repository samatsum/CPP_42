CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS_DIR = srcs
OBJS_DIR = objects

SRCS_FILES =	main.cpp \
				Serializer.cpp \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.o))

NAME = Serialization

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
#	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re

# static_cast: 関連する型間の安全な変換
# dynamic_cast: 実行時型チェック
# const_cast: const修飾子の変更
# reinterpret_cast: バイナリレベルでの再解釈