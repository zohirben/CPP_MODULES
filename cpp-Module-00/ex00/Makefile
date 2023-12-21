CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = megaphone.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET = Megaphone

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.SILENT: