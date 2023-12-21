CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp \
	Zombie.cpp \
	zombieHorde.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET = Zombie

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean
.SILENT: