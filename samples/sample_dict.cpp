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
    /*shuffle(vec.begin(), vec.end(), mt19937(random_device()()));*/
    for (int i = 0; i < 10; i++) {
        auto temp = vec[i];
        a.insert(temp, temp);
        a.print();
    }
    

    for (int i = 0; i < 10; i++) {
        auto temp = vec[i];
        a.print();
        a.remove(temp, temp);
    }
}
