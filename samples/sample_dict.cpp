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
    //shuffle(vec.begin(), vec.end(), rand_gen);
    
    Binary_Tree<int, int> btemp;
    AVL_Tree<int, int> atemp;
    RB_Tree<int, int> rbtemp;
    map<int, int> mtemp;
    
    auto start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    auto end_bin1000 = chrono::steady_clock::now();
    auto elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 1000 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 1000 " << elapsed_ms_bin1000.count() << endl;

    auto start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    auto end_AVL1000 = chrono::steady_clock::now();
    auto elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 1000 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 1000 " << elapsed_ms_AVL1000.count() << endl;

    auto start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    auto end_rb1000 = chrono::steady_clock::now();
    auto elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 1000 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 1000 " << elapsed_ms_rb1000.count() << endl;

    auto start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    auto end_map1000 = chrono::steady_clock::now();
    auto elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 1000 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 1000 " << elapsed_ms_map1000.count() << endl;
    
    N = 10000;
    //10^4
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 10^4 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10^4 " << elapsed_ms_bin1000.count() << endl;

    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10^4 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10^4 " << elapsed_ms_AVL1000.count() << endl;

    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10^4 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10^4 " << elapsed_ms_rb1000.count() << endl;

    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10^4 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10^4 " << elapsed_ms_map1000.count() << endl;
    

    N = 100000;
    //10^5
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << endl;
    cout << "Time for Binary insert 10^5 " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10^5 " << elapsed_ms_bin1000.count() << endl;

    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10^5 " << elapsed_ms_AVL1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10^5 " << elapsed_ms_AVL1000.count() << endl;

    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10^5 " << elapsed_ms_rb1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10^5 " << elapsed_ms_rb1000.count() << endl;

    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10^5 " << elapsed_ms_map1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10^5 " << elapsed_ms_map1000.count() << endl;


    vector<int> vec1;
    for (int i = 0; i < 100000; i++) {
        vec1.push_back(vec1.size());
    }
    //shuffle(vec1.begin(), vec1.end(), rand_gen);
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
        auto res = btemp.search(vec1[i]);
        if (res == NULL && res->key != vec1[i]) {
            cout << "ERROR" << endl;
        }
    }
    auto end_bins100000 = chrono::steady_clock::now();
    auto elapsed_ms_bins100000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bins100000 - start_bins100000);
    cout << endl;
    cout << "Time for Binary search 10^5 " << elapsed_ms_bins100000.count() << endl;

    auto start_AVLs100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec1[i]);
        if (res == NULL && res->key != vec1[i]) {
            cout << "ERROR" << endl;
        }
    }
    auto end_AVLs100000 = chrono::steady_clock::now();
    auto elapsed_ms_AVLs100000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVLs100000 - start_AVLs100000);
    cout << "Time for AVL search 10^5 " << elapsed_ms_AVLs100000.count() << endl;

    auto start_rbs100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec1[i]);
        if (res == NULL && res->key != vec1[i]) {
            cout << "ERROR" << endl;
        }
    }
    auto end_rbs100000 = chrono::steady_clock::now();
    auto elapsed_ms_rbs100000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rbs100000 - start_rbs100000);
    cout << "Time for RB search 10^5 " << elapsed_ms_rbs100000.count() << endl;

    auto start_maps100000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec1[i]);
        if (res->first != vec1[i]) {
            cout << "ERROR" << endl;
        }
    }
    auto end_maps100000 = chrono::steady_clock::now();
    auto elapsed_ms_maps100000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_maps100000 - start_maps100000);
    cout << "Time for map search 10^5 " << elapsed_ms_maps100000.count() << endl;

    for (int i = 0; i < N; i++) {
        btemp.remove(vec1[i]);
        rbtemp.remove(vec1[i], vec1[i]);
        atemp.remove(vec1[i]);
        mtemp.erase(vec1[i]);
    }

    //N = 1000000;
    ////10^6
    //start_bin1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    btemp.insert(vec[i], vec[i]);
    //}
    //end_bin1000 = chrono::steady_clock::now();
    //elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    //cout << endl;
    //cout << "Time for Binary insert 10^6 " << elapsed_ms_bin1000.count() << endl;
    //start_bin1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    btemp.remove(vec[i]);
    //}
    //end_bin1000 = chrono::steady_clock::now();
    //elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    //cout << "Time for Binary remove 10^6 " << elapsed_ms_bin1000.count() << endl;

    //start_AVL1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    atemp.insert(vec[i], vec[i]);
    //}
    //end_AVL1000 = chrono::steady_clock::now();
    //elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    //cout << "Time for AVL insert 10^6 " << elapsed_ms_AVL1000.count() << endl;
    //start_AVL1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    atemp.remove(vec[i]);
    //}
    //end_AVL1000 = chrono::steady_clock::now();
    //elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    //cout << "Time for AVL remove 10^6 " << elapsed_ms_AVL1000.count() << endl;

    //start_rb1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    rbtemp.insert(vec[i], vec[i]);
    //}
    //end_rb1000 = chrono::steady_clock::now();
    //elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    //cout << "Time for RB insert 10^6 " << elapsed_ms_rb1000.count() << endl;
    //start_rb1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    rbtemp.remove(vec[i], vec[i]);
    //}
    //end_rb1000 = chrono::steady_clock::now();
    //elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    //cout << "Time for RB remove 10^6 " << elapsed_ms_rb1000.count() << endl;

    //start_map1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    mtemp.insert({ vec[i], vec[i] });
    //}
    //end_map1000 = chrono::steady_clock::now();
    //elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    //cout << "Time for map insert 10^6 " << elapsed_ms_map1000.count() << endl;
    //start_map1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    mtemp.erase(vec[i]);
    //}
    //end_map1000 = chrono::steady_clock::now();
    //elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    //cout << "Time for map remove 10^6 " << elapsed_ms_map1000.count() << endl;


    //N = 10000000;
    ////10^7
    //start_bin1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    btemp.insert(vec[i], vec[i]);
    //}
    //end_bin1000 = chrono::steady_clock::now();
    //elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    //cout << endl;
    //cout << "Time for Binary insert 10^7 " << elapsed_ms_bin1000.count() << endl;
    //start_bin1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    btemp.remove(vec[i]);
    //}
    //end_bin1000 = chrono::steady_clock::now();
    //elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    //cout << "Time for Binary remove 10^7 " << elapsed_ms_bin1000.count() << endl;

    //start_AVL1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    atemp.insert(vec[i], vec[i]);
    //}
    //end_AVL1000 = chrono::steady_clock::now();
    //elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    //cout << "Time for AVL insert 10^7 " << elapsed_ms_AVL1000.count() << endl;
    //start_AVL1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    atemp.remove(vec[i]);
    //}
    //end_AVL1000 = chrono::steady_clock::now();
    //elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    //cout << "Time for AVL remove 10^7 " << elapsed_ms_AVL1000.count() << endl;

    //start_rb1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    rbtemp.insert(vec[i], vec[i]);
    //}
    //end_rb1000 = chrono::steady_clock::now();
    //elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    //cout << "Time for RB insert 10^7 " << elapsed_ms_rb1000.count() << endl;
    //start_rb1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    rbtemp.remove(vec[i], vec[i]);
    //}
    //end_rb1000 = chrono::steady_clock::now();
    //elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    //cout << "Time for RB remove 10^7 " << elapsed_ms_rb1000.count() << endl;

    //start_map1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    mtemp.insert({ vec[i], vec[i] });
    //}
    //end_map1000 = chrono::steady_clock::now();
    //elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    //cout << "Time for map insert 10^7 " << elapsed_ms_map1000.count() << endl;
    //start_map1000 = chrono::steady_clock::now();
    //for (int i = 0; i < N; i++) {
    //    mtemp.erase(vec[i]);
    //}
    //end_map1000 = chrono::steady_clock::now();
    //elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    //cout << "Time for map remove 10^7 " << elapsed_ms_map1000.count() << endl;

    N = 100000;
    //10k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 10k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 10k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 10k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 10k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 10k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 10k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 10k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 10k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 10k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 10k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 10k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 10k " << elapsed_ms_map1000.count() << endl;



    N += 100000;
    //20k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 20k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 20k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 20k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 20k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 20k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 20k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 20k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 20k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 20k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 20k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 20k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 20k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //30k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 30k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 30k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 30k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 30k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 30k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 30k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 30k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 30k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 30k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 30k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 30k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 30k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //40k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 40k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 40k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 40k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 40k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 40k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 40k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 40k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 40k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 40k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 40k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 40k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 40k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //50k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 50k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 50k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 50k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 50k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 50k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 50k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 50k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 50k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 50k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 50k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 50k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 50k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //60k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 60k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 60k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 60k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 60k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 60k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 60k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 60k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 60k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 60k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 60k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 60k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 60k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //70k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 70k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 70k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 70k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 70k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 70k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 70k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 70k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 70k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 70k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 70k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 70k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 70k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //80k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 80k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 80k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 80k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 80k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 80k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 80k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 80k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 80k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 80k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 80k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 80k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 80k " << elapsed_ms_map1000.count() << endl;


    N += 100000;
    //90k
    cout << endl;
    cout << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert 90k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = btemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary search 90k " << elapsed_ms_bin1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove 90k " << elapsed_ms_bin1000.count() << endl;

    cout << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL insert 90k " << elapsed_ms_AVL1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = atemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL search 90k " << elapsed_ms_bin1000.count() << endl;
    start_AVL1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        atemp.remove(vec[i]);
    }
    end_AVL1000 = chrono::steady_clock::now();
    elapsed_ms_AVL1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_AVL1000 - start_AVL1000);
    cout << "Time for AVL remove 90k " << elapsed_ms_AVL1000.count() << endl;

    cout << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB insert 90k " << elapsed_ms_rb1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = rbtemp.search(vec[i]);
        if (res == NULL && res->key != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB search 90k " << elapsed_ms_bin1000.count() << endl;
    start_rb1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_rb1000 = chrono::steady_clock::now();
    elapsed_ms_rb1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_rb1000 - start_rb1000);
    cout << "Time for RB remove 90k " << elapsed_ms_rb1000.count() << endl;

    cout << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map insert 90k " << elapsed_ms_map1000.count() << endl;
    start_bin1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        auto res = mtemp.find(vec[i]);
        if (res->first != vec[i]) {
            cout << "ERROR" << endl;
        }
    }
    end_bin1000 = chrono::steady_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map search 90k " << elapsed_ms_bin1000.count() << endl;
    start_map1000 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        mtemp.erase(vec[i]);
    }
    end_map1000 = chrono::steady_clock::now();
    elapsed_ms_map1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_map1000 - start_map1000);
    cout << "Time for map remove 90k " << elapsed_ms_map1000.count() << endl;
}