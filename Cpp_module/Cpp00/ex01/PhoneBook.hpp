/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:17:35 by coverand          #+#    #+#             */
/*   Updated: 2022/05/24 18:23:59 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "iostream"
#include <iomanip>

class PhoneBook
{
private:
    Contact contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    void AddContact(int *index, int *size);
    void SearchContact(int size);
    void ExitPhoneBook(void);
};

#endif