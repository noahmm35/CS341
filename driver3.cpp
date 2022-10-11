#include "bitarray.h"
#include "set.h"
#include <iostream>
#include <cstring>

int main()
{	
	char test[] = "Noah";
	char test2[] = "Taco";
	
	Set Name(strlen(test));
	Set Food(strlen(test2));
	
	Name.initialize(test,strlen(test));
	Food.initialize(test2,strlen(test2));
	
	Name.getData();
	Food.getData();
	std::cout << std::endl;
	
	std::cout << "Cardinality (name): " << Name.getCardinality() << std::endl;
	std::cout << "Cardinality (food): " << Food.getCardinality() << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Set Union A U B: " << std::endl;
	Name.setUnion(Food);
	std::cout << std::endl;
	
	std::cout << "Set Intersection A x B: " << std::endl;
	Name.setIntersection(Food);
	std::cout << std::endl;
	
	return 0;
}
