/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:25:13 by coverand          #+#    #+#             */
/*   Updated: 2022/05/24 18:06:28 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstring>

int main(void)
{
	PhoneBook   book;
	std::string cmd;
	int			index;
	int			size;

	index = 0;
	size = 0;
	while (1)
	{
		std::cout << "Enter command (ADD/SEARCH/EXIT): ";
		getline(std::cin, cmd);
		if (cmd == "EXIT")
		{
			book.ExitPhoneBook();
			return (0);
		}
		else if (cmd == "ADD")
			book.AddContact(&index, &size);
		else if (cmd == "SEARCH")
			book.SearchContact(size);
		else
		{
			std::cout << "Wrong command" << std::endl;
			std::cout << "Acceptable commands: ADD/SEARCH/EXIT" << std::endl;
		}
	}
}