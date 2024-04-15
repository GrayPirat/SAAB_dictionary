#include "dictionary_head.h"
#include < algorithm >
#include <random> 
using namespace std;

int main(){
	{
        binary_tree<int, int> temp;
        
        vector<int> v;
        for (int i = 0; i < 100; i++)
        {
            v.push_back(i);
        }
        random_device rd;
        mt19937 g(rd());

        shuffle(v.begin(), v.end(), g);
        
        for (int i = 0; i < 100; i++)
        {
            temp.insert(v[i]);
        }
        /*temp.print();*/
        
        for (int i = 0; i < 100; i++)
        {
            if (temp.remove(v[i]) == false)
            {
                system("cls");
                for (int i = 0; i < 100; i++)
                    cout << v[i] << ' ';
                return -1;
            }
                

            /*temp.print();*/
        }
        
        

		
	}
	
	
}
