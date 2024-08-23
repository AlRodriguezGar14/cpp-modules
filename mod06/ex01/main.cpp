#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int main() {
	Data* data = new Data("Hello, World!");

	uintptr_t serialized = Serializer::serialize(data);
	Data* dataCopy = Serializer::deserialize(serialized);

	std::cout	<< "Address for data: " << &data << "\n"
				<< "Address for dataCopy: " << &dataCopy << "\n"
				<< "Address for serialized: " << &serialized << "\n"
				<< "Content of data: " << data->getData() << "\n"
				<< "Content of dataCopy: " << dataCopy->getData() << "\n"
				<< "Serialized data: " << serialized << "\n"
				<< std::endl;
	if (data == dataCopy)
		std::cout << "Data and dataCopy are equal" << std::endl;
	delete data;
	return 0;
}
