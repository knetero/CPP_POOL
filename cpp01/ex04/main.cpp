#include "main.hpp"

void    replaceFile(std::string &filename, std::string &s1, std::string &s2)
{
    std::ifstream inputFile;
    inputFile.open(filename);
    if(inputFile.fail())
    {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile) 
    {
        std::cerr << "Error: Unable to create the output file." << std::endl;
        return;
    }

    std::string line;
    if(s1.empty() || s2.empty()){
        while(std::getline(inputFile, line))
        {
            outputFile << line << "\n";
        }
        return;
    }

    while(std::getline(inputFile, line))
    {
        size_t pos = 0;
        std::string modified_line;
        while(pos < line.length())
        {
            size_t found = line.find(s1, pos);
            if(found >= line.length())
            {
                modified_line += line.substr(pos);
                break;
            }
            modified_line += line.substr(pos, found - pos);
            modified_line += s2;
            pos = found + s1.length();
        }
        outputFile << modified_line << "\n";
    }
}


int main(int argc, char **argv) 
{
    if (argc != 4) 
    {
        std::cerr << " invalid arguments" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceFile(filename, s1, s2);
}
