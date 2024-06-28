#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main (){
		Data originData;
		originData.value = 42;
		
		Data* originPtr = &originData;
		
		uintptr_t serializedInt = Serializer::serialize(originPtr);
		Data* deserializedPtr = Serializer::deserialize(serializedInt);
		
		if (originPtr == deserializedPtr)
		{
		    std::cout << "success" << std::endl;
		    std::cout << "value: " << deserializedPtr->value << std::endl;
		}
		else
		{
		    std::cout << "fail" << std::endl;
		}
		
		return 0;
}
