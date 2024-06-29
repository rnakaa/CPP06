#include "ScalarConverte.hpp"

void ScalarConverte::convert(const std::string &prm){
	LiteralType literaltype = checkLiteral(prm);

	if (literaltype == CHR){
		convertFromChar(prm[0]);
	}
	else if (literaltype == INT){
		convertFromInt(std::stoi(prm));
	}
	else if (literaltype == SPC){
		convertFromSpecial(prm);
	}
	else if (literaltype == FLT){
		convertFromFloat(std::stof(prm));
	}
	else if (literaltype == DBL){
		convertFromDouble(std::stod(prm));
	}
	else if (literaltype == ERR){
		std::cerr << "ERR : input is invalid" << std::endl;
	}

}

void ScalarConverte::convertFromSpecial(std::string prm) {
	if (prm == "nan"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nan" << std::endl;
		std::cout << "double: nan" << std::endl;
		}
	else if (prm == "-inf" || prm == "-inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		}
	else if (prm == "+inf" || prm == "+inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		}
}


void ScalarConverte::convertFromChar(char c) {
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverte::convertFromInt(int i) {
	std::cout << "char: ";
	if (i >= 32 && i <= 126)
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}


void ScalarConverte::convertFromFloat(float f) {
	std::cout << "char: ";
		if (f >= 32 && f <= 126)
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (f > 2147483647 || f < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(f) << std::endl;

		if (f - static_cast<int>(f) == 0){
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		}
		else{
		std::cout << "float: " << f  << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
			
		}
}

void ScalarConverte::convertFromDouble(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d))
			std::cout << "impossible" << std::endl;
		else if (d >= 32 && d <= 126)
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (d > 2147483647 || d < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;

		if (d - static_cast<int>(d) == 0){
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
		}
		else {
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
			
		}
}

LiteralType ScalarConverte::checkLiteral(const std::string &prm){
	if (isChar(prm)){
		return CHR;
	}
	else if (isInt(prm)){
		return INT;
	}
	else if (isSpecial(prm)){
		return SPC;
	}
	else if (isFloat(prm)){
		return FLT;
	}
	else if (isDouble(prm)){
		return DBL;
	}
	return ERR;
}

bool ScalarConverte::isSpecial(const std::string &prm){
	if (prm == "-inff" || prm == "+inff" || prm == "nan" || prm == "-inf" || prm == "+inf" )
		return true;
	return false;
	}

bool ScalarConverte::isChar(const std::string &prm){
	if (prm.size() == 1 && !std::isdigit(prm[0])) {
		return true;
	}
	return false;
}

bool ScalarConverte::isInt(const std::string &prm){
	std::size_t i = 0;

	if (prm[i] == '-' || prm[i] == '+')
		i++;
	while (prm.size() > i){
		if (!std::isdigit(prm[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverte::isFloat(std::string prm){
	size_t fpos = prm.find("f");
	if (fpos == std::string::npos)
		return false;

	prm.erase(fpos,1);

	float f;
	std::istringstream iss(prm);
	iss >> f;
	if (iss.fail())
		return false;
	return true;
}

bool ScalarConverte::isDouble(std::string prm){
	try {
		std::stod(prm);
		return true;
	}
	catch(...){
		return false;
	}
}



ScalarConverte::ScalarConverte(){}

ScalarConverte::~ScalarConverte(){}

