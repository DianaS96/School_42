/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:03:15 by coverand          #+#    #+#             */
/*   Updated: 2022/05/24 17:34:22 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void	Contact::SetFirstName(std::string firstname) {
	this->first_name = firstname;
}

void	Contact::SetLastName(std::string lastname) {
	this->last_name = lastname;
}

void	Contact::SetNickName(std::string nickname) {
	this->nick_name = nickname;
}

void	Contact::SetPhoneNumber(std::string phonenumber) {
	this->phone_number = phonenumber;
}

void	Contact::SetSecret(std::string secret) {
	this->darkest_secret = secret;
}

std::string	Contact::GetFirstName(void) {
	return (this->first_name);
}

std::string	Contact::GetLastName(void) {
	return (this->last_name);
}

std::string	Contact::GetNickName(void) {
	return (this->nick_name);
}

std::string	Contact::GetPhoneNumber(void) {
	return (this->phone_number);
}

std::string	Contact::GetSecret(void) {
	return (this->darkest_secret);
}