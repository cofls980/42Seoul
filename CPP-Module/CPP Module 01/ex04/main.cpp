#include "replace.hpp"

void	string_replace(char **argv, std::ifstream *ifs, std::ofstream *ofs)
{
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;

	while (getline(*ifs, line))
	{
		std::string::size_type n = line.find(s1);
		if (n != std::string::npos)
		{
			line = line.erase(n, s1.length());
			line = line.insert(n, s2);
		}
		*ofs << line;
	}
	(*ifs).close();
	(*ofs).close();
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string file = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		if (!(file.length() && s1.length() && s2.length()))
			return (0);
		std::ifstream ifs;
		ifs.open(argv[1]);
		if (!ifs.is_open())
		{
			std::cout << "file open ERROR" << std::endl;
			return (0);
		}
		std::string rep_file = file.append(".replace");
		std::ofstream ofs(rep_file.c_str());
		if (!ofs.is_open())
		{
			std::cout << "file open ERROR" << std::endl;
			return (0);
		}
		string_replace(argv, &ifs, &ofs);
	}
	else
	{
		std::cout << "Wrong parameters!" << std::endl;
	}
	return (0);
}