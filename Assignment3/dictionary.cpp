// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "dictionary.h"
#include <cstring>

Dictionary::Dictionary()
{
	BitArray data_(0);
	lookupTable_=new int[256];
} 

Dictionary::Dictionary (const Dictionary & dict)
{
	for(int i=0; i<256; i++)
	{
		lookupTable_[i]=dict.lookupTable_[i];
	}
}

Dictionary::~Dictionary()
{
	delete [] lookupTable_;
}

void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word, size);
	data_.print();
	
	populateLookup();
}

int Dictionary::rank_range(int start, int end, int bit)
{
	int count=0;
	
	while(start!=end+1)
	{
		data_.get(start);
		
		if(data_.get(start)==bit)
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
	int c=0;
	
	for(int i=0; i<end; i++)
	{
		unsigned char z = data_.get8(i);
		
		if(z<0)
		{
			z+=256; //chars have been signed this whole time... so need to get to correct array position
			c+=lookupTable_[z];
		}
		else
		{
			c+=lookupTable_[z];
		}
		
		i+=7; //to add 8 to i after each iteration to move to next byte
	}
	
	if (bit!=1) //zero contingency
	{
		c=data_.length() - c;
	}
	
	return c;
}

int Dictionary::select(int k, int bit)
{	
	int c=0,pos=0,i=-8, y=0;
	
	while (c<k && i<data_.length())
	{
		i+=8;
		
		unsigned char z = data_.get8(i);
		y = int(z); //saving lookup table value if loop ends
		
		if(z<0)
		{
			z+=256; //signed chars
			
			if(bit!=1) //handling zero case
			{
				int w=0;
				w=8-lookupTable_[z];
				c+=w;
			}
			else
			{
				c+=lookupTable_[z];
			}
		}
		else
		{
			if(bit!=1) //handling zero case
			{
				int w=0;
				w=8-lookupTable_[z];
				c+=w;
			}
			else
			{
				c+=lookupTable_[z];
			}
		}
	}
	
	if(i>data_.length()) //contingency in case kth element is not present
	{
		std::cout << "The " << k << "th bit was not within the specified range!" << std::endl;
		return 0;
	}
	else
	{
		c=c-lookupTable_[y]; //subtract value from byte that sent c over k
		pos=i; //set pos for loop below
		
		for(int i=pos; i<pos+8; i++) //cycle thru next byte to find pos of kth
		{
			if(c==k)
			{
				i=pos+10;
			}
		
			if(data_.get(i)==bit)
			{
				c++;
				pos=i;
			}
			else
			{
				//Nothing
			}
		}
	
		return pos;
	}
}

void Dictionary::printLookupTable(std::ostream & output) //used std::cout in driver
{	
	output << "PRINTING LOOKUP TABLE..." << std::endl << std::endl;
	
	for(int i=0;i<256;i++)
	{
		output << "Lookup[" << i << "] = " << lookupTable_[i] << std::endl;
	} 
}

void Dictionary::populateLookup() //helper funciton to create lookup table
{
	for(int i=0;i<256;i++)
	{	
		char x= ' '; //char decleration to hold 8 bits as opposed to 32
		
		x=i; // give char the number
		
		char pop[1] = {x}; //put char into its own array
		
		Set S(1);
		S.initialize(pop,1); //put char into set in order to get cardinality
		
		lookupTable_[i]=S.getCardinality(); //save cardinality into lookup table slot
	}
}
