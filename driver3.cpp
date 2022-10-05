#include "bitarray.h"

int main()
{	
	BitArray Name(4);
	int check=0;
	
	Name.print();
	
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