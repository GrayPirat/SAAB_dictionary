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
    Binary_Tree<int, int> btemp(25, 25);
    btemp.insert(32, 32);
    btemp.insert(20, 20);
    btemp.insert(22, 22);
    btemp.insert(10, 10);
    btemp.insert(28, 28);
    btemp.insert(27, 27);
    btemp.insert(30, 30);
    btemp.insert(34, 34);
    btemp.insert(36, 36);
    btemp.insert(21, 21);
    btemp.insert(12, 12);
    btemp.insert(5, 5);
    btemp.insert(4, 4);
    btemp.insert(3, 3);
    btemp.insert(2, 2);
    btemp.insert(1, 1);

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
    temp.insert(21, 21);
    temp.insert(12, 12);
    temp.insert(5, 5);
    temp.insert(4, 4);
    temp.insert(3, 3);
    temp.insert(2, 2);
    temp.insert(1, 1);

    //time_t start1, end1, start2, end2;

    auto start1 = chrono::steady_clock::now();
    temp.insert(18,18);
    auto end1 = chrono::steady_clock::now();
    auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    cout << endl;
    cout << "Time for AVL insert "<< elapsed_ms1.count() << endl;

    auto start2 = chrono::steady_clock::now();
    btemp.insert(18, 18);
    auto end2 = chrono::steady_clock::now();
    auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    cout << "Time for Binary insert " << elapsed_ms2.count() << endl;

    auto start3 = chrono::steady_clock::now();
    temp.remove(18);
    auto end3 = chrono::steady_clock::now();
    auto elapsed_ms3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);
    cout << endl;
    cout << "Time for AVL remove " << elapsed_ms3.count() << endl;

    auto start4 = chrono::steady_clock::now();
    btemp.remove(18);
    auto end4 = chrono::steady_clock::now();
    auto elapsed_ms4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - start4);
    cout << "Time for Binary remove " << elapsed_ms4.count() << endl;

    auto start5 = chrono::steady_clock::now();
    temp.search(36);
    auto end5 = chrono::steady_clock::now();
    auto elapsed_ms5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - start5);
    cout << endl;
    cout << "Time for AVL search " << elapsed_ms5.count() << endl;

    auto start6 = chrono::steady_clock::now();
    btemp.search(36);
    auto end6 = chrono::steady_clock::now();
    auto elapsed_ms6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - start6);
    cout << "Time for Binary search " << elapsed_ms6.count() << endl;
    
    vector<int> vec;
    for (int i = 0; i < 1000; i++) {
        vec.push_back(vec.size());
    }

    AVL_Tree<int, int> stemp;

    vector<int> vec1(vec);
    shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
    shuffle(vec1.begin(), vec1.end(), mt19937(random_device()()));
    auto start7 = chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        stemp.insert(vec[i],vec[i]);
    }
    for (int i = 0; i < 1000; i++) {
        stemp.remove(vec1[i]);
    }
    auto end7 = chrono::steady_clock::now();
    auto elapsed_ms7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - start7);
    cout << "Time for AVL mixed overload " << elapsed_ms7.count() << endl;



}
