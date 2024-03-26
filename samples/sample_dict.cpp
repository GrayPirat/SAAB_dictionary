#include "dictionary_head.h"
using namespace std;

int main(){
	{
		Hash_Table<int, int> a(200);
		int i = 0;
		a.insert_hash(0, 0);
		a.insert_hash(1, 207);
		a.insert_hash(2, 1);
		a.insert_hash(201, 0);
		a.operator++()->second = 1;
		a.operator++()->second = 2;
		a.operator++()->second = 3;
		a.operator++()->second = 4;
		
	}
	
	
}
