#include "dictionary_head.h"
#include < algorithm >
#include <random> 
using namespace std;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

int main()
{
    AVL_Tree<int, int> temp(2,3);
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

    
}
