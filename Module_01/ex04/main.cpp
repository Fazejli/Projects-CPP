#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    std::string fileName;
    std::string s1;
    std::string s2;
    std::ifstream fd;
    std::ofstream newFd;

    if (ac != 4)
    {
        std::cerr << "Check yout inputs" << std::endl;
        return (1);
    }
    fileName = av[1];
    s1 = av[2];
    s2 = av[3];
    if (fileName.empty() || s1.empty())
    {
        std::cerr << "Filename and <s1> can not be empty" << std::endl;
        return (1);
    }
    fd(fileName);
    if (!fd.is_open())
    {
        std::cerr << "Error: cannot open file " << fileName << std::endl;
        return (1);
    }
    
    fd.close();
    return (0);
}