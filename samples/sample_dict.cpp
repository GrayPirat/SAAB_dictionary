#include "dictionary_head.h"
#include < algorithm >
#include <random> 
using namespace std;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

int main()
{
    /*AVL_Tree<int, int> temp(2,3);
    temp.insert(5, 4);
    temp.insert(7, 4);
    temp.insert(6, 4);
    temp.insert(3, 4);
    temp.insert(1, 4);
    temp.insert(0, 4);
    temp.insert(6, 4);
    temp.insert(5, 4);
    temp.insert(7, 4);
    temp.insert(8, 4);
    temp.insert(9, 4);

    temp.print();*/
    AVL_Tree<int, int> temp(25, 25);
    temp.insert(32, 32);
    temp.insert(20, 20);
    temp.insert(22, 22);
    temp.insert(10,10);
    temp.insert(28, 28);
    temp.insert(27, 27);
    temp.insert(30, 30);
    temp.insert(34, 34);
    temp.insert(36, 36);
    temp.remove(20);
    temp.print();
    temp.remove(22);
    temp.print();
}
