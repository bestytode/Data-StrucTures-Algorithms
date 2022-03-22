#include "LinkedList.h"

int main()
{
	std::cout << "1.Operation：base test" << "\n";
	std::cout << "Expected: 1 2 3 4 " << std::endl;
	LinkedList<int> list1;
	list1.push_front(2);
	list1.push_front(1);
	list1.push_back(3);
	list1.push_back(4);
	std::cout << "Result:   " << list1 << "\n\n";

	std::cout << "2.Operation：insert(0, 0), insert(5, 5), erase(3)" << "\n";
	list1.insert(0, 0); // 0 1 2 3 4 
	list1.insert(5, 5); // 0 1 2 3 4 5
	list1.erase(4);	    // 0 1 2 3 5
	std::cout << "Expected: 0 1 2 3 5 " << std::endl;
	std::cout << "Result:   " << list1 << "\n\n";	

	std::cout << "3.Operation：list[3] = 10" << "\n";
	list1[3] = 10;
	std::cout << "Expected: 0 1 2 10 5" << "\n" <<
	"Result:   " << list1 << "\n\n";

	std::cout << "4.Operation：print()" << "\n";
	std::cout << "Expected: 0 1 2 10 5" << "\n" <<
		"Result:   "; 
	list1.print();  
	std::cout << "\n\n";

	std::cout << "5.Operation：Initializer list" << "\n";
	LinkedList<int> list2 = {1, 2, 3, 4, 5};
	std::cout << "Expected: 1 2 3 4 5" "\n" <<
		"Result:   " << list2 << "\n\n";

	std::cout << "6.Operation：Copy Constructor" << "\n";
	LinkedList<int> list3 = list2;	//implicit call copy construtor
	std::cout << "Expected: 1 2 3 4 5" "\n" <<
		"Result:   " << list3 << "\n\n";

	std::cout << "7.Operation：reverse" << "\n";
	list3.reverse();
	std::cout << "Expected: 5 4 3 2 1" "\n" <<
		"Result:   " << list3 << "\n\n";

	std::cout << "8.Operation：Iterator Test, two traverse methods" << "\n";
	std::cout << "Expected: 1 2 3 4 5" "\n" <<
		"Result 1: ";
	for (LinkedList<int>::Iterator itr = list2.begin(); itr != list2.end(); itr++)
		std::cout << *itr << " "; 

	std::cout << "\nResult 2: ";
	for (const auto& i : list2)
		std::cout << i << " ";
}
