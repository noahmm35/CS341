// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

int main()
{
	RedBlackTree tree;
	std::ifstream input("data.txt");
	
	if(input.is_open())
	{
		while(!input.eof())
		{
			int data(0);
			
			input >> data;
			tree.insert(data);
		}
		input.close();
	
		std::cout << "red nodes: ";
		tree.printRedNodes(tree.getRoot());
		std::cout << std::endl;
	
		std::cout << "black nodes: ";
		tree.printBlackNodes(tree.getRoot());
		std::cout << std::endl;
	
	
		std::cout << "Root: " << tree.getRoot()->getData() << std::endl;
	}
	else
	{
		std::cout << "Error accessing file... try again!" << std::endl;
	}
	
	return 0;
}