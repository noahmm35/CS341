#include "bitarray.h"
          
BitArray::BitArray(int size)
{
	BYTES=size;
	data_= new char[BYTES];
	
	data_[0]='n';
	data_[1]='o';
	data_[2]='a';
	data_[3]='h';
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
	delete [] data_;
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