#include <gtest.h>
#include "dictionary_head.h"

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;

TEST(AVL_Tree, AVL_can_insert1000) {
	AVL_Tree<int, int> a;
	vector<int> vec;

	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	/*shuffle(vec.begin(), vec.end(), mt19937(random_device()()));*/
	for (int i = 0; i < 1000; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	//a.print();
	for (int i = 0; i < 1000; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}

TEST(AVL_Tree, AVL_remove1000) {
	AVL_Tree<int, int> a;
	vector<int> vec;

	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 1000; i++) {
		a.insert(vec[i], vec[i]);
	}
	//a.print();
	for (int i = 0; i < 1000; i++) {
		auto temp = a.search(vec[i])->value;
		EXPECT_EQ(temp, vec[i]);
	}

	for (int i = 0; i < 999; i++) {
		auto temp = a.remove(vec[i]);
		
		EXPECT_EQ(temp, true);
	}
	
}

//TEST(AVL_Tree, AVL_height10) {
//	AVL_Tree<int, int> a;
//	vector<int> vec;
//	for (int i = 0; i < 1000; i++) {
//		vec.push_back(vec.size());
//	}
//	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
//	for (int i = 0; i < 1000; i++) {
//		a.insert(vec[i], vec[i]);
//	}
//	int old_height = a.tree_height();
//	//a.print();
//	int new_height = old_height;
//	while (new_height - old_height < 10) {
//		for (int i = 0; i < 100; i++) {
//			a.remove(vec[i]);
//		}
//		for (int i = 0; i < 100; i++) {
//			int x = rand() % 1000;
//			a.insert(x, x);
//		}
//		new_height = a.tree_height();
//	}
//	ASSERT_GE(new_height - old_height, 10);
//}

TEST(AVL_Tree, AVL_can_remove) {
	Binary_Tree<int, int> a;
	a.insert(1, 1);
	a.insert(2, 2);
	a.insert(6, 6);
	a.insert(-1, -1);
	a.insert(3, 3);
	EXPECT_EQ(a.remove(3), true);
	EXPECT_EQ(a.remove(6), true);
	EXPECT_EQ(a.remove(-1), true);
}

TEST(AVL_Tree, AVL_remove_empty_false) {
	AVL_Tree<int, int> a;
	a.remove(6);
	EXPECT_NE(a.remove(10), true);
}

TEST(AVL_Tree, AVL_operator_plusplus) {
	AVL_Tree<int, int> a;
	vector<int> vec = { 1,2,6,-3,3 };//{7,2,3,-2,4}
	for (int i = 0; i < vec.size(); i++) {
		a.insert(vec[i], vec[i]);
	}
	for (int i = 0; i < a.get_size(); i++) {
		a.operator++()->value++;
	}
	for (int i = 0; i < a.get_size(); i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i] + 1);
	}
}

TEST(AVL_Tree, AVL_copy_constr) {
	AVL_Tree<int, int> a;
	vector<int> vec = { 1,2,6,-3,3 };
	for (int i = 0; i < vec.size(); i++) {
		a.insert(vec[i], vec[i]);

	}
	AVL_Tree<int, int>b(a);
	for (int i = 0; i < a.get_size(); i++) {
		b.operator++()->value += 10;
	}


	for (int i = 0; i < a.get_size(); i++) {
		EXPECT_EQ((b.search(vec[i])->value) - (a.search(vec[i])->value), 10);
	}
}

TEST(AVL_Tree, AVL_right_turn) {
	AVL_Tree<int, int> temp(20, 20);
	temp.insert(30, 30);
	temp.insert(10, 10);
	temp.insert(15, 15);
	temp.insert(5, 5);
	temp.insert(1, 1);
}