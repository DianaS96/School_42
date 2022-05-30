#include "replace.hpp"
#include <filesystem>

// Source: https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
std::string ft_replace_help(std::string buf, std::string s1, std::string s2)
{
    for (size_t pos = 0; ; pos += s2.length())
    {
        pos = buf.find(s1, pos);
        if (pos == std::string::npos)
            return (buf);
        buf.erase(pos, s1.length());
        buf.insert(pos, s2);
    }
    return (buf);
}

int ft_replace(std::string file, std::string s1, std::string s2)
{
    std::ifstream   file_to_read;
    std::ofstream   file_to_write;
    std::string     filename = file + ".replace";
    std::string     buf;
    file_to_read.open(file, std::fstream::in | std::fstream::out);
    if (file_to_read.is_open())
    {
        file_to_write.open(filename);
        if (file_to_write.is_open())
        {
            while (!file_to_read.eof())
            {
                getline(file_to_read, buf);
                file_to_write << ft_replace_help(buf, s1, s2) << std::endl;
            }
            file_to_write.close();
        }
        else
        {
            if (errno)
                std::cout << FRED << filename << " : " << strerror(errno) << NONE << std::endl;
            return (1);
        }        
    }
    else
    {
        if (errno)
            std::cout << FRED << file << " : " << strerror(errno) << NONE << std::endl;
        return (1);
    }
    file_to_read.close();
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << FRED << "Wrong number of arguments!" << NONE << std::endl;
        std::cout << FRED << "Usage: ./replace [file] [str1] [str2]" << NONE << std::endl;
        return (1);
    }
    return (ft_replace(argv[1], argv[2], argv[3]));
}