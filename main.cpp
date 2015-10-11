#include <iostream>
#include "genBST.h"
using namespace std;

int main(int argc, char const *argv[])
{
    BST<int> A;
    A.insert(10);
    A.insert(5);
    A.insert(12);
    A.insert(50);
    A.insert(1);
    A.insert(72);
    A.insert(18);
    A.insert(3);
    A.insert(9);
    cout << "breadth: " << endl;
    A.breadthFirst();
    cout << endl;
    cout << "preorder: " << endl;
    A.preorder();
    cout << endl;

    cout << "postorder: " << endl;
    A.postorder();
    cout << endl;

    cout << "inorder: "<< endl;
    A.inorder();
    cout << endl;

    cout << "iterative Preorder: "<< endl;
    A.iterativePreorder();
    cout << endl;

    cout << "iterative Postorder: "<< endl;
    A.iterativePostorder();
    cout << endl;
    return 0;
}