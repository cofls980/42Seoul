#include <iostream>
#include <fstream>

void	string_replace(char **argv, std::ifstream *ifs, std::ofstream *ofs)
{
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if ((*ifs).is_open() && (*ofs).is_open())
	{
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
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string file = "";
		file.append(argv[1]);

		std::ifstream ifs;
		ifs.open(file.data(), std::ios::in);//에러 처리
		if (!ifs)
		{
			std::cout << "file open ERROR" << std::endl;
			return (0);
		}
		std::string rep_file = file.append(".replace");
		std::ofstream ofs(rep_file.data(), std::ios::out | std::ios::trunc);
		if (ofs.fail())
		{
			std::cout << "file open ERROR" << std::endl;
		}
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		string_replace(argv, &ifs, &ofs);
	}
	else
	{
		std::cout << "Wrong parameters!" << std::endl;
	}
	return (0);
}