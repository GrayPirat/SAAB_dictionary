#include <gtest.h>
#include "dictionary_head.h"

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

TEST(Binary_Tree, bintree_can_insert) {
	Binary_Tree<int, int> a;
	vector<int> vec;
	int ind = rand()%15;
	for (int i = 0; i < 30; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 30; i++) {
		a.insert(vec[i]);
	}
	a.print();
	//ASSERT_EQ(a.search_tree(234), 234);
}

TEST(Binary_Tree, bintree_insert1000) {

}

TEST(Binary_Tree, bintree_can_remove) {
	Binary_Tree<int, int> a;
	a.insert(1);
	a.insert(2);
	a.insert(6);
	a.insert(0);
	a.insert(3);
	EXPECT_EQ(a.remove(3), true);
	EXPECT_EQ(a.remove(6), true);
	EXPECT_EQ(a.remove(0), true);
}

TEST(Binary_Tree, bintree_cant_remove_empty) {
	Binary_Tree<int, int> a;
	a.remove(6);
}