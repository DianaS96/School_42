/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:18:49 by coverand          #+#    #+#             */
/*   Updated: 2022/05/24 18:29:16 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::ExitPhoneBook() {
	std::cout << "Au revoir!" << std::endl;
}

void    PhoneBook::AddContact(int *index, int *size) {
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string secret;

	std::cout << "Enter firstname: ";
	getline(std::cin, firstname);
	
	std::cout << "Enter lastname: ";
	getline(std::cin, lastname);

	std::cout << "Enter nickname: ";
	getline(std::cin, nickname);

	std::cout << "Enter phonenumber: ";
	getline(std::cin, phonenumber);

	std::cout << "Enter secret: ";
	getline(std::cin, secret);

	if (*index == 8)
		*index = 0;
	contacts[*index].SetFirstName(firstname);
	contacts[*index].SetLastName(lastname);
	contacts[*index].SetNickName(nickname);
	contacts[*index].SetPhoneNumber(phonenumber);
	contacts[*index].SetSecret(secret);
	*index += 1;
	if (*size < 8)
		*size += 1;
}

std::string    ft_check_length(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str.append(".");
	}
	return (str);
}

void    PhoneBook::SearchContact(int size)
{
	int			i;
	std::string	input;   
	int			ind;

	i = 0;
	ind = 0;
	if (size == 0)
	{
		std::cout << "There is no contacts in phonebook yet!" << std::endl;
		return ;
	}
	
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "FirstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	while (i < size)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << ft_check_length(contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << ft_check_length(contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << ft_check_length(contacts[i].GetNickName()) << std::endl;
		i++;
	}

	std::cout << "Enter index: ";
	getline(std::cin, input);
	ind = std::stoi(input);
	if (ind < 0 || ind >= size)
	{
		std::cout << "Index should be non-negative and less or equal than " << (size - 1) << std::endl;
		return ;
	}
	else
	{
		std::cout << "First name: " << contacts[ind].GetFirstName() << std::endl;
		std::cout << "Last name: " << contacts[ind].GetLastName() << std::endl;
		std::cout << "Nickname: " << contacts[ind].GetNickName() << std::endl;
		std::cout << "Phone number: " << contacts[ind].GetPhoneNumber() << std::endl;
		std::cout << "Secret: " << contacts[ind].GetSecret() << std::endl;
	}
}