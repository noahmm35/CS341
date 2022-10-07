#include "bitarray.h"
#include <iostream>
#include <string>

int main()
{	
	int size=0;
	char * word = new char[4];
	word[0]= 'n';
	word[1]= 'o';
	word[2]= 'a';
	word[3]= 'h';
	
	size=sizeof(word)/sizeof(char);
	
	std::cout << "Size: " << size << std::endl;
	
	BitArray Name(size);
	Name.initialize(word,size);
	
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