#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }


bool isPseudoLiteral(const std::string& s) {
	return (s == "nan" || s == "nanf" ||
		s == "+inf" || s == "+inff" ||
		s == "-inf" || s == "-inff");
}

void printPseudoLiteral(const std::string &s) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (s == "nan" || s == "nanf") {
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (s[0] == '+') {
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else {
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	return;
}

bool isCharLiteral(const std::string& s) {
	if (s.length() == 3) {
		if (s[0] == '\'' && s[2] == '\'')
			return true;
		else return false; 
	}
	else return false;
}

void printChar(double value) {
	std::cout << "char: ";
	if (value < 0 || value > 127 || std::isnan(value))
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";
}

bool isInt(const std::string& s)
{
	if (s.empty())
		return false;

	size_t i = 0;
	bool digitFound = false;

	if (s[i] == '+' || s[i] == '-')
		i++;

	if (i >= s.length())
		return false;
	for (; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return false;
		digitFound = true;
	}

	return digitFound;
}

void printInt(double value) {
	std::cout << "int: ";
	if (value > INT_MAX || value < INT_MIN || std::isnan(value) || std::isinf(value))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";
}

bool isDouble(const std::string& s)
{
	if (s.empty())
		return false;

	size_t i = 0;
	int dotCount = 0;
	bool digitFound = false;

	if (s[i] == '+' || s[i] == '-')
		i++;

	if (i >= s.length())
		return false;

	for (; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			digitFound = true;
		else if (s[i] == '.')
		{
			dotCount++;
			if (dotCount > 1)
				return false;
		}
		else return false;
	}

	if (!digitFound)
		return false;

	return true;
}

void printDouble(double value) {
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1)
			  << value << "\n";
}

bool isFloat(const std::string& s)
{
	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;

	std::string tmp = s.substr(0, s.length() - 1);

	return isDouble(tmp);
}

void printFloat(double value) {
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1)
			  << static_cast<float>(value) << "f\n";
}

void ScalarConverter::convert(const std::string& string) {
	double value = 0.0;

	if (isPseudoLiteral(string)) {
		printPseudoLiteral(string);
		return;
	}

	if (isCharLiteral(string))
		value = static_cast<double>(string[1]);

	else if (isInt(string))
		value = std::strtod(string.c_str(), NULL);

	else if (isFloat(string))
		value = std::strtod(string.substr(0, string.length() - 1).c_str(), NULL);

	else if (isDouble(string))
		value = std::strtod(string.c_str(), NULL);

	else {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}