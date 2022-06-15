#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Target", 145, 137), target("Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    Form::execute(executor);

    std::string filename = target + "_shrubbery";
    std::ofstream file;
    file.open(filename);
    if (file.is_open())
    {
        file << \
        "                  |" << std::endl <<
        "                 |.|" << std::endl <<
        "                 |.|" << std::endl <<
        "                |\\./|" << std::endl <<
        "                |\\./|" << std::endl <<
        ".               |\\./|               ." << std::endl <<
        " \\^.\\          |\\\\.//|          /.^/" << std::endl <<
        "  \\--.|\\       |\\\\.//|       /|.--/" << std::endl <<
        "    \\--.| \\    |\\\\.//|    / |.--/" << std::endl <<
        "     \\---.|\\    |\\./|    /|.---/" << std::endl <<
        "        \\--.|\\  |\\./|  /|.--/" << std::endl <<
        "           \\ .\\  |.|  /. /" << std::endl <<
        " _ -_^_^_^_-  \\ \\ // /  -_^_^_^_- _" << std::endl <<
        "   - -/_/_/- ^ ^  |  ^ ^ -\\_\\_\\- -" << std::endl;
        file.close();
    }
    else
        throw ShrubberyCreationForm::FileCannnotBeOpened();
    
    

}
