NAME = ft_container

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic #-fsanitize=address
INCLUDES = -Iinc
RM = rm -rf

SRC_PATH = src
OBJ_PATH = obj
ANNOYING = .vscode

MAIN = main.cpp
SRC = testVector.cpp testStack.cpp testMap.cpp
OBJ = ${addprefix ${OBJ_PATH}/, ${SRC:.cpp=.o}}

all: ${NAME}

${NAME}: ${OBJ} $(MAIN)
	@${CXX} ${CXXFLAGS} ${INCLUDES} -o ${NAME} ${MAIN} ${OBJ}

${OBJ_PATH}/%.o: ${SRC_PATH}/%.cpp
	@mkdir -p ${@D}
	@${CXX} ${CXXFLAGS} ${INCLUDES} -c $< -o $@

test: fclean all
	./ft_container

leaks: fclean all
	./ft_container leaks

clean:
	@${RM} ${ANNOYING}
	@${RM} ${OBJ_PATH}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY = all clean fclean re
