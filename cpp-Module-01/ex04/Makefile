CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Functions.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET =  replace

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp Replace.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean
.SILENT: