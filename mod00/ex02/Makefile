CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I ./

SRC =	Account.cpp \
		tests.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = account_test

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking the object files to create the executable..."
	@$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	@echo "Compiling the source file $< into the object file $@..."
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@echo "Removing the object files..."
	@rm -f $(OBJ) *.gch

fclean: clean
	@echo "Removing the executable..."
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
