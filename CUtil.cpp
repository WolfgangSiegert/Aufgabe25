/*#pragma once
#include <iostream>
#include <regex>*/
#include "CUtil.hpp"

double CUtil::checkDoubleInput(){
		bool firsttime (true);
		std::string str;
		std::regex regex_double("^-?(?:0|[1-9][0-9]*)\\.?[0-9]+$"); //("-?[0-9]+|-?[0-9]+.?[0-9]+"); //("[+-]?\\d*\\.?\\d+");
		while(!std::regex_match(str,regex_double)){
			if (!firsttime){
				std::cout << "\nGeben Sie eine positive Zahl ein. Verwenden Sie nur die Ziffern 0-9.\nTrennen Sie Nachkommastellen ggf. mit '.' ab.\n";
				std::cout << "erneute Eingabe: ";
			}
			std::cin >> str;
			firsttime = false;
		};

		return std::stod(str);            
};

int CUtil::checkIntegerInput(){
		bool firsttime (true);
		std::string str;
		std::regex regex_double("^(0|[1-9][0-9]*)$"); //("-?[0-9]+");
		while(!std::regex_match(str,regex_double)){
			if (!firsttime){
				std::cout << "\nGeben Sie eine positive Ganzzahl ein. Verwenden Sie nur die Ziffern 0-9.\n";
				std::cout << "erneute Eingabe: ";
			}
			std::cin >> str;
			firsttime = false;
		};
		return std::stoi(str);    
};

