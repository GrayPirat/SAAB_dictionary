#include <gtest.h>
#include "dictionary_head.h"
//
//COORD position, newPosition;
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//int x = 0, y = 0;

TEST(Binary_Tree, bintree_can_insert1000) {
	Binary_Tree<int, int> a;
	vector<int> vec;
	vec.push_back(-1);
	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 1000; i++) {
		a.insert(vec[i], vec[i]);
	}
	//a.print();
	for (int i = 0; i < 1000; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}

TEST(Binary_Tree, bintree_remove1000) {
	Binary_Tree<int, int> a;
	vector<int> vec;
	
	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 1000; i++) {
		a.insert(vec[i],vec[i]);
	}
	//a.print();
	for (int i = 0; i < 1000; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
	//shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 100; i++) {
		/*auto temp = vec[i];
		auto temp1 = a.search(temp)->value;*/
		EXPECT_EQ(a.remove(vec[i]), true);
	}
}

TEST(Binary_Tree, bintree_height10) {
	Binary_Tree<int, int> a;
	vector<int> vec;
	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 1000; i++) {
		a.insert(vec[i],vec[i]);
	}
	int old_height = a.tree_height();
	//a.print();
	int new_height = old_height;
	while (new_height - old_height < 10) {
		for (int i = 0; i < 100; i++) {
			a.remove(vec[i]);
		}
		for (int i = 0; i < 100; i++) {
			int x = rand() % 1000;
			a.insert(x,x);
		}
		new_height = a.tree_height();
	}
	ASSERT_GE(new_height-old_height, 10);
}

TEST(Binary_Tree, bintree_can_remove) {
	Binary_Tree<int, int> a;
	a.insert(1,1);
	a.insert(2,2);
	a.insert(6,6);
	a.insert(-1,-1);
	a.insert(3,3);
	EXPECT_EQ(a.remove(3), true);
	EXPECT_EQ(a.remove(6), true);
	EXPECT_EQ(a.remove(-1), true);
}

TEST(Binary_Tree, bintree_remove_empty_false) {
	Binary_Tree<int, int> a;
	a.remove(6);
	EXPECT_NE(a.remove(10), true);
}

TEST(Binary_Tree, bintree_operator_plusplus) {
	Binary_Tree<int, int> a;
	vector<int> vec = { 1,2,6,-3,3 };//{7,2,3,-2,4}
	for (int i = 0; i < vec.size(); i++) {
		a.insert(vec[i], vec[i]);
	}
	for (int i = 0; i < a.get_size(); i++) {
		a.operator++()->value++;
	}
	for (int i = 0; i < a.get_size(); i++) {
		EXPECT_EQ(a.search(vec[i] + 1)->value, vec[i]+1);
	}
}

TEST(Binary_Tree, bintree_copy_constr) {
	Binary_Tree<int, int> a;
	vector<int> vec = { 1,2,6,-3,3 };
	for (int i = 0; i < vec.size(); i++) {
		a.insert(vec[i],vec[i]);

	}
	Binary_Tree<int, int>b(a);
	for (int i = 0; i < a.get_size(); i++) {
		b.operator++()->value += 10;
	}
	
	
	for (int i = 0; i < a.get_size(); i++) {
		EXPECT_EQ((b.search(vec[i] + 10)->value) - (a.search(vec[i])->value), 10);
	}
}