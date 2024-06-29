#include <iostream>
#include <string>
#include <sstream>


enum LiteralType{
	CHR,
	INT,
	FLT,
	DBL,
	ERR,
	SPC,
};

class ScalarConverte{
	public :
		static void convert(const std::string &prm);
		static LiteralType checkLiteral(const std::string &prm);
		static bool isChar(const std::string &prm);
		static bool isInt(const std::string &prm);
		static bool isFloat(std::string prm);
		static bool isDouble(std::string prm);
		static void convertFromChar(char c);
		static void convertFromInt(int i);
		static void convertFromFloat(float f);
		static void convertFromDouble(double d);
		static void convertFromSpecial(std::string prm);
		static bool isSpecial(const std::string &prm);

	private:
		ScalarConverte();
		~ScalarConverte();
};
