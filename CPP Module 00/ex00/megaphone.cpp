#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABKE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1;i < argc;i++)
		{
			for (int j = 0;argv[i][j];j++)
			{
				if ('a' <= argv[i][j] && argv[i][j] <= 'z')
					argv[i][j] -= 32;
				std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}