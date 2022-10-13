// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "dictionary.h"

Dictionary::Dictionary()
{
	BitArray data_(0);
} 

Dictionary::Dictionary (const Dictionary & dict)
{
	
}

Dictionary::~Dictionary()
{
	delete [] lookupTable_;
}

void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word, size);
	data_.print();
}

int Dictionary::rank_range(int start, int end, int bit)
{
	int count=0;
	
	while(start!=end+1)
	{
		data_.get(start);
		
		if(data_.get(start))
		{
			count++;
		}
		else
		{
			//blank
		}
		start++;
	}
	
	return count;
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
	int pos=0,count=0;
	
	for(int i=start; i<=end; i++)
	{
		if(count==k)
		{
			i=end+1;
		}
		
		if(data_.get(i)==bit)
		{
			pos=i;
			count++;
		}
		else
		{
			//Nothing
		}
		
	}
	
	if (count!=k)
	{
		std::cout << "The " << k << "th bit was not within the specified range!" << std::endl;
		return 0;
	}
	else
		return pos;
}

int Dictionary::rank(int end, int bit)
{
	return rank_range(0,end,bit);
}

int Dictionary::select(int k, int bit)
{
	return select_range(0,data_.length(),k,bit);
}

void Dictionary::printLookupTable(std::ostream & output)
{
	//nothing yet
}