#include "dictionary_head.h"
using namespace std;

int main(){
	Hash_Table<string, int> test;
	test.insert_hash("haha", 1);
	test.insert_hash("haha", 3);
	test.insert_hash("haha", 5);
	test.insert_hash("bad", 5);

	/*test.remove_hash("haha");*/
	/*test["bad"]->second;*/
	
	/*Hash_Table<int, string> test2;
	test2.insert_hash(234, "sgsdg");*/
}
