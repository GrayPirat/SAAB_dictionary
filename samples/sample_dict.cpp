#include "dictionary_head.h"
#include < algorithm >
#include <random> 
using namespace std;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

int main()
{
    Binary_Tree<int, int> a;
    a.insert(1);
    a.insert(2);
    a.insert(6);
    a.insert(-1);
    a.insert(3);
    a.print();
    a.remove(3);
    a.print();
    a.remove(6);
    a.print();
    a.remove(-1);
    a.print();
    /* Binary_Tree<int, int> temp;
    temp.insert(3);
    temp.insert(4);
    temp.insert(2);
    temp.insert(6);
    temp.insert(5);
    temp.insert(9);
    temp.insert(7);
    temp.insert(8);


    temp.insert(10);


    temp.print();
    temp.remove(6);
    temp.print();
    */


}
