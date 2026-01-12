NAME = replace
TEST = tester
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_SRC = test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST): $(NAME) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -o $(TEST)

test: $(TEST)
	./$(TEST)

clean :
	rm -rf $(OBJS) $(TEST_OBJ)
	rm -rf $(wildcard tests/*.replace)
	rm -rf $(wildcard *.replace)

fclean : clean
	rm -rf $(NAME) $(TEST)
	
re : fclean all

.PHONY: all clean fclean re test