#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main (){
		Data sampleData;
		sampleData.value = 42;
		sampleData.character = 'A';
		
		Data* originalPtr = &sampleData;
		
		uintptr_t serialized = Serializer::serialize(originalPtr);
		Data* deserializedPtr = Serializer::deserialize(serialized);
		
		if (originalPtr == deserializedPtr)
		{
		    std::cout << "Serialization and deserialization successful!" << std::endl;
		    std::cout << "Original value: " << deserializedPtr->value << std::endl;
		    std::cout << "Original character: " << deserializedPtr->character << std::endl;
		}
		else
		{
		    std::cout << "Serialization and deserialization failed!" << std::endl;
		}
		
		return 0;
}
