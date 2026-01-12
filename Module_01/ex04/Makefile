NAME = replace
TESTER = test
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

$(TESTER): $(NAME) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(TEST)

test: $(TESTER)
	./$(TESTER)

clean :
	rm -rf $(OBJS) $(TEST_OBJ)
	rm -f test1.txt.replace test2.txt.replace test3.txt.replace

fclean : clean
	rm -rf $(NAME) $(TESTER)
	
re : fclean all

.PHONY: all clean fclean re test