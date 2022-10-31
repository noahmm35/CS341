
// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "bitarray.h"
          
BitArray::BitArray(int size)
{
	data_=nullptr;
}

BitArray::BitArray(const BitArray & array) : BYTES(array.BYTES)
{
	for(int i=0; i<array.BYTES; i++)
	{
		data_[i]=array.data_[i];
	}
}

BitArray::~BitArray()
{
	if(data_!=nullptr)
	{
		delete [] data_;
	}
}

bool BitArray::get(int position) const
{
	int shift=0;	
	shift=(-(position%8)+7);
	
	return get8(position) & (1 << shift);
}

// void print()
void BitArray::print()
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

char BitArray::get8(int position) const
{
	return data_[position/8];
}

bool BitArray::flip(int position)
{
	char hold;
	bool b=0;
	int shift=0;	
	shift=(-(position%8)+7);
	
	b = get8(position) & (1 << shift);
	
	if(b)
	{
		hold=get8(position) ^ (1 << shift);
		data_[position/8]=hold;
		return 1;
	}
	else
	{
		hold=get8(position) | (1 << shift);
		data_[position/8]=hold;
		return 1;
	}
} 

bool BitArray::set(int position, int bit)
{
	bool b=0;
	int shift=0;	
	shift=(-(position%8)+7);
	
	b = get8(position) & (1 << shift);
	
	if(b!=bit)
	{
		flip(position);
		return 1;
	}
	else
	{
		return 0;
	}
} 

void BitArray::complement()
{
	for(int i=0;i<LENGTH;i++)
	{
		flip(i);
	}
}

void BitArray::clear()
{
	for (int i=0; i<BYTES; i++)
	{
		data_[i]=0;
	}
}

void BitArray::initialize(char * word, int size)
{
	BYTES=size;
	LENGTH=8*BYTES;
	data_= new char[BYTES];
	
	for(int i=0;i<size;i++)
	{
		data_[i]=word[i];
	}
}

void BitArray::set8(char c, int index)
{
	data_[index]=c;
}
