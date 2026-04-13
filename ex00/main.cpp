#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./converter <literal>\n";
        return 1;
    }

    std::string input = argv[1];

    std::cout << "Input: " << input << "\n";
    std::cout << "----------------------\n";

    ScalarConverter::convert(input);

    std::cout << "----------------------\n";

    return 0;
}