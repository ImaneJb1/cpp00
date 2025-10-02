#include <iostream>
#include <string>

void	print_args(char *argv, char *next)
{
	int i;

	i = 0;
	while(argv[i])
	{
		if(std::isalpha(argv[i]))
			std::cout << (char)std::toupper(argv[i]);
		else
			std::cout << argv[i];
		i++;
	}
	if(next)
		std::cout << " ";
}


int main(int argc, char **argv)
{
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return(0);
	}
	for(int i = 1; argv[i]; i++)
		print_args(argv[i], argv[i+1]);
	std::cout << "\n";
	
	return 0;
}
