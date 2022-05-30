/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:18:50 by coverand          #+#    #+#             */
/*   Updated: 2022/05/24 17:21:53 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
public:
    Contact(/* args */);
    ~Contact();
    void SetFirstName(std::string firstname);
    void SetLastName(std::string lastname);
    void SetNickName(std::string nickname);
    void SetPhoneNumber(std::string phonenumber);
    void SetSecret(std::string secret);
    std::string GetFirstName(void);
    std::string GetLastName(void);
    std::string GetNickName(void);
    std::string GetPhoneNumber(void);
    std::string GetSecret(void);
};

#endif