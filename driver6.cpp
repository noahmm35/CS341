// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe
#include <iostream>
#include <fstream>
#include "HashTableArray.h"
#include "HashTableCuckoo.h"
#include "HashTableChaining.h"

int main()
{
	std::ifstream input1("duplicates.txt");
	std::ifstream input2("duplicates.txt");
	std::ifstream input3("duplicates.txt");
	std::ifstream input4("duplicates.txt");
	
	int choice(0),choice2(0), size(0), r(0),s(0);
	std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl << std::endl;
	std::cout << "1) Linear Probing" << std::endl;
	std::cout << "2) Quadratic Probing" << std::endl;
	std::cout << "3) Seperate Chaining" << std::endl;
	std::cout << "4) Cuckoo Hashing" << std::endl;
	std::cout << "5) Quit Program" << std::endl << std::endl;
	
	while(choice!=5)
	{	
		std::cout << "Please enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl;
		
		if(choice >5 || choice <1)
		{
			std::cout << "Not a valid option... please try again!" << std::endl;
		}
		else if(choice!=5)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> size;
			std::cout << std::endl;
		
			if(choice==1)
			{
				if(input1.is_open())
				{
					choice2=0;
				
					HashTableArray hta(size);
					hta.setSize(size);
					hta.setProbe(true);
					
					while(!input1.eof())
					{
						int k(0), v(0);
						input1 >> k;
						input1 >> v;
						hta.insert(k,v);
					}
					
					hta.print();
					
					while(choice2!=4)
					{
						std::cout << "What would you like to do?" << std::endl;
						std::cout << "1) Search for Entry" << std::endl;
						std::cout << "2) Remove Entry" << std::endl;
						std::cout << "3) Print Hash Table" << std::endl;
						std::cout << "4) Return to Main Menu" << std::endl << std::endl;
					
						std::cout << "Please enter your choice: ";
						std::cin >> choice2;
						std::cout << std::endl;
					
						if(choice2>4 || choice2<1)
						{
							std::cout << "Not a valid option... please try again!" << std::endl;
						}
						else if(choice2!=4)
						{
							if(choice2==1)
							{
								std::cout << "Search (please enter key): ";
								std::cin >> s;
								std::cout << std::endl;
							
								hta.search(s);
							}
							else if(choice2==2)
							{
									std::cout << "Remove (please enter key): ";
									std::cin >> r;
									std::cout << std::endl;
								
									hta.remove(r);
							}
							else if(choice2==3)
							{
								hta.print();
							}
						}
					}
					
					input1.close();
				}
				else
					std::cout << "error opening file... please try again!" << std::endl << std::endl;
			}
			else if(choice==2)
			{
				if(input2.is_open())
				{
					choice2=0;
				
					HashTableArray hta(size);
					hta.setSize(size);
					hta.setProbe(false);
					
					while(!input2.eof())
					{
						int k(0), v(0);
						input2 >> k;
						input2 >> v;
						hta.insert(k,v);
					}
					
					hta.print();
					
					while(choice2!=4)
					{
						std::cout << "What would you like to do?" << std::endl;
						std::cout << "1) Search for Entry" << std::endl;
						std::cout << "2) Remove Entry" << std::endl;
						std::cout << "3) Print Hash Table" << std::endl;
						std::cout << "4) Return to Main Menu" << std::endl << std::endl;
					
						std::cout << "Please enter your choice: ";
						std::cin >> choice2;
						std::cout << std::endl;
					
						if(choice2>4 || choice2<1)
						{
							std::cout << "Not a valid option... please try again!" << std::endl;
						}
						else if(choice2!=4)
						{
							if(choice2==1)
							{
								std::cout << "Search (please enter key): ";
								std::cin >> s;
								std::cout << std::endl;
							
								hta.search(s);
							}
							else if(choice2==2)
							{
									std::cout << "Remove (please enter key): ";
									std::cin >> r;
									std::cout << std::endl;
								
									hta.remove(r);
							}
							else if(choice2==3)
							{
								hta.print();
							}
						}
					}
					
					input2.close();
				}
				else
					std::cout << "error opening file... please try again!" << std::endl << std::endl;
			}
			else if(choice==3)
			{
				if(input3.is_open())
				{
					choice2=0;
				
					HashTableChaining htch(size);
					htch.setSize(size);
					
					while(!input3.eof())
					{
						int k(0), v(0);
						input3 >> k;
						input3 >> v;
						htch.insert(k,v);
					}
					
					htch.print();
					
					while(choice2!=4)
					{
						std::cout << "What would you like to do?" << std::endl;
						std::cout << "1) Search for Entry" << std::endl;
						std::cout << "2) Remove Entry" << std::endl;
						std::cout << "3) Print Hash Table" << std::endl;
						std::cout << "4) Return to Main Menu" << std::endl << std::endl;
					
						std::cout << "Please enter your choice: ";
						std::cin >> choice2;
						std::cout << std::endl;
					
						if(choice2>4 || choice2<1)
						{
							std::cout << "Not a valid option... please try again!" << std::endl;
						}
						else if(choice2!=4)
						{
							if(choice2==1)
							{
								std::cout << "Search (please enter key): ";
								std::cin >> s;
								std::cout << std::endl;
							
								htch.search(s);
							}
							else if(choice2==2)
							{
									std::cout << "Remove (please enter key): ";
									std::cin >> r;
									std::cout << std::endl;
								
									htch.remove(r);
							}
							else if(choice2==3)
							{
								htch.print();
							}
						}
					}
					
					input3.close();
				}
				else
					std::cout << "error opening file... please try again!" << std::endl << std::endl;
			}
			else if(choice==4)
			{
				if(input4.is_open())
				{
					choice2=0;
				
					HashTableCuckoo htcu(size);
					htcu.setSize(size);
					
					while(!input4.eof())
					{
						int k(0), v(0);
						input4 >> k;
						input4 >> v;
						htcu.insert(k,v);
					}
					
					htcu.print();
					
					while(choice2!=4)
					{
						std::cout << "What would you like to do?" << std::endl;
						std::cout << "1) Search for Entry" << std::endl;
						std::cout << "2) Remove Entry" << std::endl;
						std::cout << "3) Print Hash Table" << std::endl;
						std::cout << "4) Return to Main Menu" << std::endl << std::endl;
					
						std::cout << "Please enter your choice: ";
						std::cin >> choice2;
						std::cout << std::endl;
					
						if(choice2>4 || choice2<1)
						{
							std::cout << "Not a valid option... please try again!" << std::endl;
						}
						else if(choice2!=4)
						{
							if(choice2==1)
							{
								std::cout << "Search (please enter key): ";
								std::cin >> s;
								std::cout << std::endl;
							
								htcu.search(s);
							}
							else if(choice2==2)
							{
									std::cout << "Remove (please enter key): ";
									std::cin >> r;
									std::cout << std::endl;
								
									htcu.remove(r);
							}
							else if(choice2==3)
							{
								htcu.print();
							}
						}
					}
					
					input4.close();
				}
				else
					std::cout << "error opening file... please try again!" << std::endl << std::endl;
			}
			else
			{
				std::cout << "we should not have arrived here :(" << std::endl;
			}
			std::cout << "What would you like to do next?" << std::endl;
			std::cout << "1) Linear Probing" << std::endl;
			std::cout << "2) Quadratic Probing" << std::endl;
			std::cout << "3) Seperate Chaining" << std::endl;
			std::cout << "4) Cuckoo Hashing" << std::endl;
			std::cout << "5) Quit Program" << std::endl << std::endl;
		}
	}
	
	
	return 0;
}