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

	Dictionary Name;
	Name.initialize(test,strlen(test));
	
	
	std::cout << "Rank: " << Name.rank(31,1) << std::endl;
	std::cout << "Rank Range (0,15): " << Name.rank_range(0, 15, 1) << std::endl;
	std::cout << "Select (9,1): " << Name.select(9,1) << std::endl;
	std::cout << "Select Range (16,31,2,1): " << Name.select_range(16, 31, 2, 1) << std::endl;
	
	std::cout << "\n";
	
	return 0;
}
