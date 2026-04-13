# COLOURS
RED     = \033[1;31m
GREEN   = \033[1;32m
BLUE    = \033[1;34m
RESET   = \033[0;0m
MAGENTA = \033[35m
YELLOW	= \033[33m;
BOLD    = \033[1m
PINK    = \033[38;5;206m
CYAN    = \033[1;36m

NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = bin

SRCS = main.cpp Serializer.cpp Data.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "${BOLD}${CYAN}${NAME} ${PINK}compiled successfully!${RESET}\n"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@printf "${MAGENTA}Compiling ${CYAN}$<${RESET}\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "${RED}Cleaned object directory and files!${RESET}\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${BOLD}${RED}${NAME} deleted!${RESET}\n"

re: fclean all

.PHONY: all clean fclean re