#include "bitarray.h"
#include <iostream>
#include <cstring>

int main()
{	
	char test[] = "Noah";
	
	BitArray Name(strlen(test));
	
	Name.initialize(test,strlen(test));
	
	Name.print();
	std::cout << std::endl;
	
	std::cout << "0th bit set: " << Name.get(0) << std::endl;
	std::cout << "10th bit set: " << Name.get(10) << std::endl << std::endl;
	
	std::cout << "Setting 0th bit to 1..." << std::endl;
	Name.flip(0);
	Name.print();
	
	std::cout << std::endl;
	
	std::cout << "Setting 10th bit to 0..." << std::endl;
	Name.flip(10);
	Name.print();
	
	std::cout << std::endl;
	
	std::cout << "Complement: " << std::endl;
	Name.complement();
	Name.print(); 
	
	std::cout << std::endl;
	
	std::cout << "Clear BitArray: " << std::endl;
	Name.clear();
	Name.print(); 
	
	return 0;
}
