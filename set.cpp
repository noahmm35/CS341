#include "set.h"

Set::Set(int size)
{
	BitArray data_(size);
}

Set::~Set()
{
	//delete [] data_;
}

void Set::initialize(char * word, int size)
{
	data_.initialize(word, size);
}

int Set::getCardinality() const
{
	int count=0;
	
	for(int i=0; i<data_.length(); i++)
	{
		data_.get(i);
		
		if(data_.get(i))
		{
			count++;
		}
		else
		{
			//Nothing
		}
	}
	
	return count;
}

BitArray & Set::getData()
{
	data_.print();
	return data_;
} 

bool Set::setUnion(Set & B)
{
	if(data_.length()==B.data_.length())
	{
		for(int i=0;i<data_.length();i++)
		{
			char x=data_.get(i);
			char y=B.data_.get(i);
			
			x=x|y;
			
			data_.set(i,x);
		}
		
		data_.print();
		
		return 1;
	}
	else
	{
		std::cout << "Unequal Lengths... Set Union impossible!" << std::endl;
		return 0;
	}
}

bool Set::setIntersection(Set & B)
{
	if(data_.length()==B.data_.length())
	{
		for(int i=0;i<data_.length();i++)
		{
			char x=data_.get(i);
			char y=B.data_.get(i);
			
			x=x&y;
			
			data_.set(i,x);
		}
		
		data_.print();
		
		return 1;
	}
	else
	{
		std::cout << "Unequal Lengths... Set Intersection impossible!" << std::endl;
		return 0;
	}
}