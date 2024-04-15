#include "dictionary_head.h"
using namespace std;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

int main(){
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

        for (int i = 0; i < temp.size_of_tree(); i++)
        {
            temp.operator++()->value = 1;
            temp.print();
        }
        temp.insert(100);
        temp.operator++()->value = 99;
        temp.print();
        temp.operator++()->value = 99;
        temp.print();

    		*/
	}
	
	
}
