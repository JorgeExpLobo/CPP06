#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cctype> 

class ScalarConverter {

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
	
	public:
		static void convert(const std::string& string);
};