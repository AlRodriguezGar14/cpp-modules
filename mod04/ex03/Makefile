CXX = g++ -g3

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I ./

SRCS =	Character.cpp \
		main.cpp \
		Cure.cpp \
		Ice.cpp \
		AMateria.cpp \
		MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = ex03

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking the object files to create the executable..."
	@$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	@echo "Compiling the source file $< into the object file $@..."
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@echo "Removing the object files..."
	@rm -f $(OBJS) *.gch

fclean: clean
	@echo "Removing the executable..."
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
	
