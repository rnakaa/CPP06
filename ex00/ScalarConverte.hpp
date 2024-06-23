#include <iostream>
#include <string>
#include <string>


enum LiteralType{
	CHR,
	INT,
	FLT,
	DBL,
	ERR,
};

class ScalarConverte{
	public :
		static void convert(const std::string &prm);
		static LiteralType checkLiteral(const std::string &prm);
		static bool isChar(const std::string &prm);
		static bool isInt(const std::string &prm);
		static bool isFloat(const std::string &prm);
		static bool isDouble(const std::string &prm);

	private:
		ScalarConverte();
		~ScalarConverte();
};
