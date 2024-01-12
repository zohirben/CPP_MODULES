CPP = c++

CPPFLAGS = #-Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET =  scavtrap

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean
.SILENT: