#include "dictionary_head.h"
using namespace std;

int main(){
	{
		binary_tree<int, int> temp;
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
	

		
	}
	
	
}
