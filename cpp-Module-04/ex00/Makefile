CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET =  animalv1

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp Wrongcat.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean
.SILENT: