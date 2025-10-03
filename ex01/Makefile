CPP= c++
NAME= phonebook
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRC=  PhoneBook.cpp parse_input.cpp contact.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME) clean

%.o : %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $@

clean: $(OBJ)
	@rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all



