// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "bitarray.h"
#include "set.h"
#include "dictionary.h"
#include <iostream>
#include <cstring>

int main()
{	
	char test[] = "Noah";

	Dictionary d;
	d.initialize(test, strlen(test));
	
	std::cout << "Rank: " << d.rank(31,1) << std::endl;
	std::cout << "Select (9,1): " << d.select(9,1) << std::endl << std::endl;
	
	d.printLookupTable(std::cout);
	
	return 0;
}
