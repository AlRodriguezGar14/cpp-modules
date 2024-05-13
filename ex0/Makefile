CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = megaphone

all: $(TARGET)

# $@ target
# $^ prerequisites
$(TARGET): $(OBJ)
	@echo "Linking the object files to create the executable..."
	@$(CXX) $(CXXFLAGS) -o $@ $^

# $@ target
# $^ prerequisites
%.o: %.cpp
	@echo "Compiling the source file $< into the object file $@..."
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@echo "Removing the object files..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing the executable..."
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
