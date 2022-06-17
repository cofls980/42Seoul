#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	count = 0;
	oldest = 0;
}

void	PhoneBook::add(Contact user)
{
	if (count == 8)
	{
		users[oldest] = user;
		oldest++;
		if (oldest == 8)
			oldest = 0;
	}
	else
	{
		users[count] = user;
		count++;
	}
}

int	PhoneBook::display(void)
{
	if (count == 0)
		return (0);
	std::cout << std::right;
	std::cout << std::setw(10) << "index" << " | ";
	std::cout << std::setw(10) << "first name" << " | ";
	std::cout << std::setw(10) << "last name" << " | ";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0;i < count;i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		users[i].display();
	}
	return (1);
}

int	PhoneBook::search(int index)
{
	if (1 <= index && index <= count)
	{
		users[index - 1].display_specific_contact();
		return (1);
	}
	else
	{
		std::cout << "WRONG NUMBER. TRY AGAIN!" << std::endl;
		return (0);
	}
}


void	PhoneBook::lost_contacts(void)
{
	std::cout << "THE CONTACTS ARE LOST FOREVER!" << std::endl;
}