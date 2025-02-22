/* 
1. A move constructor is a constructor where instead of making a deep copy of the original's data and adding it to the new object, the 
new object will point to the memory of the original object, and the original object's main pointer is null.

2. A move assignment operator performs in the same process as a move constructor, except it is invoked on an object that was already
constructed. A move constructor is invoked on an object that is being initialized.

Big-O Analysis:
	BST::empty()	- 	Returns a true/false for one conditional. Always executes only once. Big-O: O(1)

	BST::add()		-	add() invokes addHelper(), which traverses through BST to insert a new node. Because BSTs might not be balanced, it
	is possible that a node has to traverse through every node to be added, meaning it calls addHelper() n times. Big-O: O(n)

	BST::makeEmpty()	-	makeEmpty() invokes makeEmptyHelper(). Worst case is where there is a skewed tree, requiring n traversals
	to get to the node to start deleting from. Big-O: O(n)

	BST::printLevelOrder()	-	This function does not use recursion but a while loop. It loops n times, where n is the number of 
	nodes. Big-O: O(n)

	BST::cloneTree()	-	cloneTree() visits every node only once. So, execution increases by n as n amount of nodes increases. 
	Big(O): O(n) 
*/

#include <iostream>
#include "BST.h" 

int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/
	BST<string> bst_test = {"C", "p", "t", "s", "2", "3" , "B", "S", "T"};

	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    a. Level-order print
	    a. Post-order print
	    a. Pre-order print */

	cout << "In order print: " << endl;
	bst_test.printInOrder();
	cout << "\nLevel order print: " << endl;
	bst_test.printLevelOrder();
	cout << "\nPost order print: " << endl;
	bst_test.printPostOrder();
	cout << "\nPre order print: " << endl;
	bst_test.printPreOrder();
	cout << "\n";

	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/
	
	BST<string> bst_copy1(bst_test);
	if (bst_copy1.nodesCount() == bst_test.nodesCount() && bst_copy1.contains("B") && bst_copy1.contains("S") && bst_copy1.contains("T"))
	{
		cout << "Copy constructor test-1 passed!" << endl;
	}
	else
	{
		cout << "Copy constructor test-1 failed!\nLevel order print of bst_copy1: ";
		bst_copy1.printLevelOrder();
		cout << "\nLevel order print of bst_test: ";
		bst_test.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   // bst_copy1.getNode("B")->setValue("A");
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/
	
	bst_copy1.getNode("B")->setValue("A");

	if (bst_copy1.contains("A") && bst_test.contains("B") && !bst_test.contains("A"))
	{
		cout << "Copy constructor test-2 passed!" << endl;
	}
	else
	{
		cout << "Copy constructor test-2 failed!\nLevel order print of bst_test: ";
		bst_test.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/

	BST<string> bst_copy2 = bst_test;
	if (bst_copy2.nodesCount() == bst_test.nodesCount() && bst_copy2.contains("B") && bst_copy2.contains("S") && bst_copy2.contains("T"))
	{
		cout << "Copy assignment operator test passed!" << endl;
	}
	else
	{
		cout << "Copy assignment operator test failed!\nLevel order print of bst_copy1: ";
		bst_copy2.printLevelOrder();
		cout << "\nLevel order print of bst_test: ";
		bst_test.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/

	BST<string> bst_move1 = move(bst_test);
	if (bst_move1.nodesCount() == 9 && bst_move1.contains("B") && bst_move1.contains("S") && bst_move1.contains("T") && bst_test.empty())
	{
		cout << "Move constructor test passed!" << endl;
	}
	else
	{
		cout << "Move constructor test failed!\nLevel order print of bst_move1: ";
		bst_move1.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the mesaage: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/

	BST<string> bst_move2;
	BST<string> bst_temp = {"B","S","T"};
	bst_move2 = move(bst_temp);

	if (bst_move2.nodesCount() == 3 && bst_move2.contains("B") && bst_move2.contains("S") && bst_move2.contains("T"))
	{
		cout << "Move assignment operator test passed!" << endl;
	}
	else
	{
		cout << "Move assignment operator test failed!\nLevel order print of bst_move2: ";
		bst_move2.printLevelOrder();
	}

	return 0;
}