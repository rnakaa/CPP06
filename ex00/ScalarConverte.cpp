#include "ScalarConverte.hpp"

void ScalarConverte::convert(const std::string &prm){
	LiteralType literaltype = checkLiteral(prm);
	std::cout << literaltype << std::endl;


}

LiteralType ScalarConverte::checkLiteral(const std::string &prm){
	if (isChar(prm)){
		std::cout << "is Char" << std::endl;
		return CHR;
	}
	else if (isInt(prm)){
		std::cout << "is Int" << std::endl;
		return INT;
	}
	else if (isFloat(prm)){
		std::cout << "is Flout" << std::endl;
		return FLT;
	}
	return ERR;
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
	if (prm.size() == 1 && !std::isdigit(prm[0])) {
		return true;
	}
	return false;
}





















ScalarConverte::ScalarConverte(){}

ScalarConverte::~ScalarConverte(){}

