CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Array.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET = array

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp Array.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean
.SILENT: