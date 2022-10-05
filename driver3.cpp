#include "bitarray.h"

int main()
{	
	BitArray Name(4);
	
	Name.print();
	
	std::cout << "Number of bits: " << Name.getLength() << std::endl;
	
	//just to test my get function
	for(int i=0;i<32;i++)
	{
		if(i%8==0)
		{
			std::cout << "|";
		}
		std::cout << Name.get(i);
	}
	
	std::cout << std::endl;
	
	return 0;
}