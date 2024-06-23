#include <iostream>
#include "ScalarConverte.hpp"

int main(int argc, const char **argv){
	if (argc != 2){
		std::cerr << "ERROR: not enogh argument" << std::endl;
		return 1;
	}
	else{
		try {
			ScalarConverte::convert(argv[1]);
		}
		catch(const std::exception &e){
			std::cerr << "ERROR: " << e.what() << std::endl;	
			return 1;
		}
	}
}
