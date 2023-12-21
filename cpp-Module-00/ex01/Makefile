CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = Main.cpp \
	GettersAndSetters.cpp \
	Contact.cpp \
	PhoneBook.cpp 

OBJ = $(SOURCE:.cpp=.o)

TARGET = PhoneBook

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp PhoneBook.hpp Contact.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean
.SILENT: