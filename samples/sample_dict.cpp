#include "dictionary_head.h"
using namespace std;

int main(){
	{
		Hash_Table<string, int> test(20);
		test.insert_hash("haha", 1);
		test.insert_hash("haha", 3);
		test.insert_hash("haha", 5);
		test.insert_hash("bad", 5);
		test.remove_hash("bad");

		test["bad"]->second = 5;
		test.operator++()->second=1;
		test.operator++()->second=1;
	}
	
	
}
