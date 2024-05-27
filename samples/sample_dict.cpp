#include"dictionary_head.h"
#include<algorithm>
#include<random>
#include<iostream>
#include<chrono>
#include<map>
using namespace std;

vector<int> vec;

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

void calculate_insert(int n) {
    for (int i = 0; i < n; i++) {
        vec.push_back(vec.size());
    }
    Binary_Tree<int, int> btemp;
    AVL_Tree<int, int> atemp;
    RB_Tree<int, int> rbtemp;
    map<int, int> mtemp;

    auto start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        btemp.insert(vec[i], vec[i]);
    }
    auto end_bin1000 = chrono::high_resolution_clock::now();
    auto elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary insert " << n << " " << elapsed_ms_bin1000.count() << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        atemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL insert " << n << " " << elapsed_ms_bin1000.count() << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        rbtemp.insert(vec[i], vec[i]);
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB insert " << n << " " << elapsed_ms_bin1000.count() << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        mtemp.insert({ vec[i], vec[i] });
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map insert " << n << " " << elapsed_ms_bin1000.count() << endl;

    cout << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        btemp.remove(vec[i]);
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for Binary remove " << n << " " << elapsed_ms_bin1000.count() << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        atemp.remove(vec[i]);
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for AVL remove " << n << " " << elapsed_ms_bin1000.count() << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        rbtemp.remove(vec[i], vec[i]);
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for RB remove " << n << " " << elapsed_ms_bin1000.count() << endl;

    start_bin1000 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        mtemp.erase(vec[i]);
    }
    end_bin1000 = chrono::high_resolution_clock::now();
    elapsed_ms_bin1000 = std::chrono::duration_cast<std::chrono::milliseconds>(end_bin1000 - start_bin1000);
    cout << "Time for map remove " << n << " " << elapsed_ms_bin1000.count() << endl;

}


int main()
{
    cout << "Vvedi chislo: ";
    int n;
    cin >> n;
    cout << endl;
    calculate_insert(n);


    /*AVL_Tree<int, int> a;
    vector<int> vec;
    const int N = 10;

    for (int i = 0; i < N; i++) {
        vec.push_back(vec.size());
    }
    auto rand_gen = mt19937(0);
    shuffle(vec.begin(), vec.end(), rand_gen);
    for (int i = 0; i < N; i++) {
        a.insert(vec[i], vec[i]);
        a.print();
    }*/
}