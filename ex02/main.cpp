#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
	srand(static_cast<unsigned int>(time(NULL)));
	int random = rand() % 3;
	switch (random)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}

void identify(Base * base){
	if (dynamic_cast<A*>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C" << std::endl;
	else
		std::cout << "ERR" << std::endl;
}


void identify(Base& base){
	try{
		A& a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast&) {
		try
		{
			B& b = dynamic_cast<B&>(base);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast&) {
			try
			{
				C& c = dynamic_cast<C&>(base);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast&) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main(){
	Base * base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
