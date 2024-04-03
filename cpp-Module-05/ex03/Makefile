CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp

OBJ = $(SOURCE:.cpp=.o)

TARGET =  Intern

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp Intern.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean
.SILENT: