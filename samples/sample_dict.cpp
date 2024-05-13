#include"dictionary_head.h"
#include<algorithm>
#include<random>
#include<iostream>
#include<chrono>
#include<map>
using namespace std;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

int main()
{
    int N = 1000;
    vector<int> vec;
    for (int i = 0; i < 100000000; i++) {
        vec.push_back(vec.size());
    }
    auto rand_gen = mt19937(0);
    shuffle(vec.begin(), vec.end(), rand_gen);
    
    Binary_Tree<int, int> btemp;
    AVL_Tree<int, int> atemp;
    RB_Tree<int, int> rbtemp;
    map<int, int> mtemp;
    
    auto start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    auto end_bin1000 = chrono::steady_clock::now();
    auto elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 1000 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 1000 " << elapsed_ms_bin1000.count() << endl;

    auto start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    auto end_AVL1000 = chrono::steady_clock::now();
    auto elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 1000 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 1000 " << elapsed_ms_AVL1000.count() << endl;

    auto start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    auto end_rb1000 = chrono::steady_clock::now();
    auto elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 1000 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 1000 " << elapsed_ms_rb1000.count() << endl;

    auto start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    auto end_map1000 = chrono::steady_clock::now();
    auto elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 1000 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 1000 " << elapsed_ms_map1000.count() << endl;
    
    N = 10000;
    //10^4
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 10^4 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10^4 " << elapsed_ms_bin1000.count() << endl;

    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10^4 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10^4 " << elapsed_ms_AVL1000.count() << endl;

    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10^4 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10^4 " << elapsed_ms_rb1000.count() << endl;

    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10^4 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10^4 " << elapsed_ms_map1000.count() << endl;
    

    N = 100000;
    //10^5
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 10^5 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10^5 " << elapsed_ms_bin1000.count() << endl;

    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10^5 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10^5 " << elapsed_ms_AVL1000.count() << endl;

    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10^5 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10^5 " << elapsed_ms_rb1000.count() << endl;

    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10^5 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10^5 " << elapsed_ms_map1000.count() << endl;


    vector<int> vec1;
    for (int i = 0; i < 100000; i++) {
        vec1.push_back(vec1.size());
    }
    shuffle(vec1.begin(), vec1.end(), rand_gen);
    //search 10^5
    for (int i = 0; i < N; i++) {
        btemp.insert(vec1[i], vec1[i]);
        atemp.insert(vec1[i], vec1[i]);
        rbtemp.insert(vec1[i], vec1[i]);
        mtemp.insert({ vec1[i], vec1[i] });
    }
    shuffle(vec1.begin(), vec1.end(), rand_gen);
    auto start_bins100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.search(vec1[i]);
    }
    auto end_bins100000 = chrono::steady_clock::now();
    auto elapsed_ms_bins100000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bins100000 - start_bins100000);
    cout << endl;
    cout << "Time for Binary search 10^5 " << elapsed_ms_bins100000.count() << endl;

    auto start_AVLs100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.search(vec1[i]);
    }
    auto end_AVLs100000 = chrono::steady_clock::now();
    auto elapsed_ms_AVLs100000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVLs100000 - start_AVLs100000);
    cout << "Time for AVL search 10^5 " << elapsed_ms_AVLs100000.count() << endl;

    auto start_rbs100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.search(vec1[i]);
    }
    auto end_rbs100000 = chrono::steady_clock::now();
    auto elapsed_ms_rbs100000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rbs100000 - start_rbs100000);
    cout << "Time for RB search 10^5 " << elapsed_ms_rbs100000.count() << endl;

    auto start_maps100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.find(vec1[i]);
    }
    auto end_maps100000 = chrono::steady_clock::now();
    auto elapsed_ms_maps100000 = std::chrono::duration_cast<std::chrono::microseconds>(end_maps100000 - start_maps100000);
    cout << "Time for map search 10^5 " << elapsed_ms_maps100000.count() << endl;

    for (int i = 0; i < N; i++) {
        btemp.remove(vec1[i]);
        rbtemp.remove(vec1[i], vec1[i]);
        atemp.remove(vec1[i]);
        mtemp.erase(vec1[i]);
    }

    N = 1000000;
    //10^6
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 10^6 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10^6 " << elapsed_ms_bin1000.count() << endl;

    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10^6 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10^6 " << elapsed_ms_AVL1000.count() << endl;

    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10^6 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10^6 " << elapsed_ms_rb1000.count() << endl;

    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10^6 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10^6 " << elapsed_ms_map1000.count() << endl;


    N = 10000000;
    //10^7
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 10^7 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10^7 " << elapsed_ms_bin1000.count() << endl;

    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10^7 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10^7 " << elapsed_ms_AVL1000.count() << endl;

    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10^7 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10^7 " << elapsed_ms_rb1000.count() << endl;

    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10^7 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::microseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10^7 " << elapsed_ms_map1000.count() << endl;

    


    auto start3 = chrono::steady_clock::now();
    atemp.remove(18);
    auto end3 = chrono::steady_clock::now();
    auto elapsed_ms3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
    cout << endl;
    cout << "Time for AVL remove " << elapsed_ms3.count() << endl;

    auto start4 = chrono::steady_clock::now();
    btemp.remove(18);
    auto end4 = chrono::steady_clock::now();
    auto elapsed_ms4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
    cout << "Time for Binary remove " << elapsed_ms4.count() << endl;

    auto start5 = chrono::steady_clock::now();
    atemp.search(36);
    auto end5 = chrono::steady_clock::now();
    auto elapsed_ms5 = std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5);
    cout << endl;
    cout << "Time for AVL search " << elapsed_ms5.count() << endl;

    auto start6 = chrono::steady_clock::now();
    btemp.search(36);
    auto end6 = chrono::steady_clock::now();
    auto elapsed_ms6 = std::chrono::duration_cast<std::chrono::microseconds>(end6 - start6);
    cout << "Time for Binary search " << elapsed_ms6.count() << endl;

    AVL_Tree<int, int> stemp;

    //vector<int> vec1(vec);
    shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
    auto start7 = chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        stemp.insert(vec[i], vec[i]);
    }
    shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
    for (int i = 0; i < 1000; i++) {
        stemp.remove(vec[i]);
    }
    auto end7 = chrono::steady_clock::now();
    auto elapsed_ms7 = std::chrono::duration_cast<std::chrono::microseconds>(end7 - start7);
    cout << "Time for AVL mixed overload " << elapsed_ms7.count() << endl;
}