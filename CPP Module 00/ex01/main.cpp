//#include <iostream>
#include "PhoneBook.hpp"

void	add_contact(PhoneBook* phone_book)
{
	std::string fn, ln, nn, ph, ds;

	Contact user2;
	user2.add();
	(*phone_book).add(user2);
}

void	search_contact(PhoneBook phone_book)
{
	int index;

	if (phone_book.display())
	{
		while (1)
		{
			std::cout << "CONTACT INDEX> ";
			std::cin >> index;
			if (phone_book.search(index) != 0)
				break ;
		}
	}
	else
	{
		std::cout << "DO NOT HAVE CONTACTS!" << std::endl;
	}
}

int main(void)
{
	PhoneBook phone_book;
	std::string command;

	while (1)
	{
		std::cout << "User> ";
		std::cin >> command;
		if (command.compare("EXIT") == 0)
			break ;
		if (command.compare("ADD") == 0)
			add_contact(&phone_book);
		else if (command.compare("SEARCH") == 0)
			search_contact(phone_book);
		else
			std::cout << "TRY AGAIN!" << std::endl;
	}
	// phonebook 비우기
}