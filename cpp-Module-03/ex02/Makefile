CPP = c++

CPPFLAGS = #-Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET =  fragtrap

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean
.SILENT: