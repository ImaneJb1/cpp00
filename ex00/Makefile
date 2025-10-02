CPP= c++
NAME= megaphone
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= megaphone.cpp
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



