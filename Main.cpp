#include<iostream>
#include<queue>
#include<stack>
#include"BST.h"

int main()
{
	BST<int> ob;
	ob.insert(4);
	ob.insert(2);
	ob.insert(19);
	ob.insert(22);
	ob.insert(1);
	ob.insert(3);
	ob.insert(21);
	ob.insert(24);
	ob.insert(14);
	ob.insert(12);
	ob.insert(17);
	ob.insert(10);
	cout << endl;
	cout << "heght iter- " << ob.height_iter() << endl;
	cout << "heght rec- " << ob.height_rec() << endl;
	cout << "zigzag traversal- ";
	ob.zigzag_iter();
	ob.printLevelOrder();
	ob.printPreOrder();
	ob.printInOrder();
	ob.printPostOrder();
	ob.remove(14);
	cout << endl;
	cout << "max lenght iterative- " << ob.max_width_iter() << endl;
	cout << endl;
	cout << "leaf count iterative- " << ob.leaf_count_iter() << endl;
	cout << "leaf count recursive method- " << ob.leafcount_rec() << endl;
	cout << "half node count iterative method- " << ob.halfNodeCount_iter() << endl;
	cout << "full nodes count- " << ob.fullNodeCount_rec() << endl;
	cout << "is binary  tree strict- " << boolalpha << ob.strictBinaryTree_rec() << endl;
	cout << "find element 14- " <<boolalpha << ob.find(14) << endl;
	ob.printLevelOrder();
	ob.printPreOrder();
	ob.printInOrder();
	ob.printPostOrder();
	return 0;
}