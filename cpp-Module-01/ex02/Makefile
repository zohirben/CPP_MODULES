CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET =  brain

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean
.SILENT: