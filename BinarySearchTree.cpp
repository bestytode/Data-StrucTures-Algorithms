#include"BinaryTree.h"
#include<iostream>
using namespace std;

/*	测试用例结构
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
	BinaryTree tree = { 5, 8, 6, 7, 2, 3, 1, 9, 4 };

	//得到 5 2 1 3 4 8 6 7 9
	tree.print(TraverseFlag::PRE_ORDER);
	cout << endl;

	//得到 1 2 3 4 5 6 7 8 9
	cout << tree << endl;

	//得到 1 4 3 2 7 6 9 8 5
	tree.print(TraverseFlag::POST_ORDER);
	cout << endl;

    //得到 5 2 8 1 3 6 9 4 7 
	tree.print(TraverseFlag::LEVEL_ORDER);
	cout << endl;

	//tree.erase(5);
	tree.insert(10);

	//得到 1 2 3 4 6 7 8 9 10
	cout << tree;
	cout << endl;

	cout << "minValue = " << tree.minValue() << endl;
	cout << "maxValue = " << tree.maxValue() << endl;
}
