#include "dictionary_head.h"
#include<algorithm>
#include<random>
#include<iostream>
#include<chrono>
using namespace std;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

int main()
{
    /*RB_Tree<int, int> temp;*/
   /* temp.insert(1, 1);
    temp.insert(2, 2);
    temp.insert(3, 3);
    temp.insert(4, 4);
    temp.insert(5, 5);
    temp.insert(0, 0);
    temp.insert(-2, -2);*/

    /*temp.insert(2, 2);
    temp.insert(0,0);
    temp.insert(-2, -2);
    temp.insert(-3, -3);
    temp.insert(-3, -3);*/

    RB_Tree<int, int> a;
    vector<int> vec;

    for (int i = 0; i < 1000; i++) {
        vec.push_back(vec.size());
    }
    shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
    for (int i = 0; i <1000; i++) {
        auto temp = vec[i];
        a.insert(temp, temp);

    }
    /*a.insert(0, 0);
    a.print();
    a.insert(4,4);
    a.print();
    a.insert(3,3);
    a.print();
    a.insert(6,6);
    a.print();
    a.insert(9, 9);
    a.print();
    a.insert(1,1);
    a.print();
    a.insert(7,7);
    a.print();
    a.insert(5,5);
    a.print();
    a.insert(8,8);
    a.print();
    a.insert(2,2);
    
    
    
    

    
    
    
    

    a.print();;

    a.remove(0, 0);
    a.print();
    a.remove(4, 4);
    a.print();
    a.remove(3, 3);
    a.print();
    a.remove(6, 6);
    a.print();
    a.remove(9, 9);
    a.print();
    a.remove(1, 1);
    a.print();
    a.remove(7, 7);
    a.print();
    a.remove(5, 5);
    a.print();
    a.remove(8, 8);
    a.print();
    a.remove(2, 2);*/

    for (int i = 0; i <1000; i++) {
        auto temp = vec[i];
       
        if (a.remove(temp, temp) == false)
        {
            return -1;
        }
        

    }
   
    

}
