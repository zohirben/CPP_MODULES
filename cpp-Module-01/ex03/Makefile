CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SOURCE = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET = weapon

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean
.SILENT: