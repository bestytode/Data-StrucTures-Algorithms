#include"BST.h"

/*	Test BST Structure
		 5
	   /   \
	  2     8
	 / \   / \
	1   3 6   9
		 \ \
		  4 7
*/

int main()
{
	BinarySearchTree tree;
	tree = { 5, 8, 6, 7, 2, 3, 1, 9, 4 };

	// Get 5 2 1 3 4 8 6 7 9
	tree.print(TraverseFlag::PRE_ORDER);
	std::cout << std::endl;

	// Get 1 2 3 4 5 6 7 8 9
	std::cout << tree << std::endl;

	// Get 1 4 3 2 7 6 9 8 5
	tree.print(TraverseFlag::POST_ORDER);
	std::cout << std::endl;

	// Get 5 2 8 1 3 6 9 4 7 
	tree.print(TraverseFlag::LEVEL_ORDER);
	std::cout << std::endl;

	//tree.erase(5);
	tree.insert(10);

	// Get 1 2 3 4 6 7 8 9 10
	std::cout << tree << std::endl;

	std::cout << "minValue = " << tree.minValue() << std::endl;
	std::cout << "maxValue = " << tree.maxValue() << std::endl;
}
