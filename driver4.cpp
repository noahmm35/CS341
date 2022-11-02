// Honor Pledge: 

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"

int main()
{	
	DoublyLinkedList dll;
	
	int data(0),bdh(0);
	std::ifstream input1("data.txt"); 
	
	//inserting initial data into the DLL
	if(input1.is_open())
	{
		while(!input1.eof())
		{
			input1 >> data;
			
			dll.insertLinkedNode(dll.getTail(),data);
		}
		
		dll.printList();
		std::cout << std::endl;
		
		input1.close();
		
		std::ifstream input2("inserts.txt");
		
		if(input2.is_open())
		{
			while(!input2.eof())
			{
				int countHead(0), countTail(0);
				input2 >> data;
				
				countHead = dll.countHeadHops(data);
				countTail = dll.countTailHops(data);
				
				if(countTail > countHead)
				{	
					LinkedNode * insert = dll.getHead();
					
					for(int i=0;i<countHead;i++)
					{
						insert=insert->getNextLinkedNode();
					}
					
					dll.insertBeforeLinkedNode(insert, data);
					
					bdh+=countHead;
				}
				else
				{
					LinkedNode * insert = dll.getTail();
					
					for(int i=0;i<countTail;i++)
					{
						insert=insert->getPrevLinkedNode();
					}
					
					dll.insertAfterLinkedNode(insert, data);
					
					bdh+=countTail;
				}
				dll.printList(); //NOTE if you do not want to see the list after every insertion, just comment this line out :)
			}
			
			input2.close();
		}
		else
		{
			std::cout << "Error opening inserts.txt file... please try again!" << std::endl;
		} 
	}
	else
	{
		std::cout << "Error opening data.txt file... please try again!" << std::endl;
	} 
	
	DoublyLinkedList dllsort;	
	
	int data2(0),bdh2(0);
	std::ifstream input3("sorted.txt"); 
	
	//inserting initial data into the DLLsort
	if(input3.is_open())
	{
		while(!input3.eof())
		{
			input3 >> data2;
			
			dllsort.insertLinkedNode(dllsort.getTail(),data2);
		}
		
		dllsort.printList();
		std::cout << std::endl;
		
		input3.close();
		
		std::ifstream input4("inserts.txt");
		
		if(input4.is_open())
		{
			while(!input4.eof())
			{
				int countHead(0), countTail(0);
				input4 >> data2;
				
				countHead = dllsort.countHeadHops(data2);
				countTail = dllsort.countTailHops(data2);
				
				if(countTail > countHead)
				{	
					LinkedNode * insert = dllsort.getHead();
					
					for(int i=0;i<countHead;i++)
					{
						insert=insert->getNextLinkedNode();
					}
					
					dllsort.insertBeforeLinkedNode(insert, data2);
					
					bdh2+=countHead;
				}
				else
				{
					LinkedNode * insert = dllsort.getTail();
					
					for(int i=0;i<countTail;i++)
					{
						insert=insert->getPrevLinkedNode();
					}
					
					dllsort.insertAfterLinkedNode(insert, data2);
					
					bdh2+=countTail;
				}
				dllsort.printList(); //NOTE if you do not want to see the list after every insertion, just comment this line out :)
			}
			
			std::ofstream output("output.txt");
			
			output << "Total number of BIG DAWG HOPS (unsorted): " << bdh << std::endl << "Total number of BIG DAWG HOPS (sorted): " << bdh2;
			
			output.close();
			
			std::cout << "UNSORTED FINAL PRODUCT: " << std::endl;
			dll.printList();
			std::cout << std::endl;
			
			std::cout << "SORTED FINAL PRODUCT: " << std::endl;
			dllsort.printList();
			std::cout << std::endl;
			
			input4.close();
		}
		else
		{
			std::cout << "Error opening inserts.txt file... please try again!" << std::endl;
		} 
	}
	else
	{
		std::cout << "Error opening sorted.txt file... please try again!" << std::endl;
	} 
	
	return 0;
}
