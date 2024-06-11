#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
    Tree<char*> copac(100);
    copac.add_node(nullptr, "1");
    copac.add_node(copac.root, "2");
    copac.add_node(copac.root, "3");
    copac.add_node(copac.root, "5");
    copac.insert_node(copac.root, "4");
    copac.add_node(copac.root, "6");
    copac.sort(copac.root, compara);
    copac.printNodes(copac.root);
    cout << endl << copac.count(copac.root)<<endl;

    Node<char*>* foundNode = copac.findNode(copac.root, "7");

    if (foundNode != nullptr) {
        cout << "Value found: " << foundNode->value << endl;
    }
    else {
        cout << "Value not found." << endl;
    }

    return 0;
}