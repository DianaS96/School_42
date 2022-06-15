#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cmath>
#include <exception>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"

/*end color*/
# define NONE        "\033[0m"

class IntNotFound : public std::exception
{
    public:
        virtual const char* what() const throw() {
            return ("Element not found!");
        }

};

template <typename T>
int easyfind(T &a, int b) {
    typename T::iterator it;
    
    it = std::find(a.begin(), a.end(), b);
    if (it != a.end())
        return (*it);
    else
        throw ::IntNotFound();

}

#endif