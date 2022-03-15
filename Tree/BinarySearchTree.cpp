#include"BST.h"
using namespace std;

/*	Test Tree Structure
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
	BinarySearchTree tree = { 5, 8, 6, 7, 2, 3, 1, 9, 4 };

	// Get 5 2 1 3 4 8 6 7 9
	tree.print(TraverseFlag::PRE_ORDER);
	cout << endl;

	// Get 1 2 3 4 5 6 7 8 9
	cout << tree << endl;

	// Get 1 4 3 2 7 6 9 8 5
	tree.print(TraverseFlag::POST_ORDER);
	cout << endl;

        // Get 5 2 8 1 3 6 9 4 7 
	tree.print(TraverseFlag::LEVEL_ORDER);
	cout << endl;

	//tree.erase(5);
	tree.insert(10);

	// Get 1 2 3 4 6 7 8 9 10
	cout << tree << endl;
	
	cout << "minValue = " << tree.minValue() << endl;
	cout << "maxValue = " << tree.maxValue() << endl;
}
