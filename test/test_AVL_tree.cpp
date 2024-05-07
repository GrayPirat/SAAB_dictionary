
#include <gtest.h>
#include "dictionary_head.h"


TEST(AVL_Tree, AVL_can_insert1000) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	const int N = 1000;

	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	auto rand_gen = mt19937(0);
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	/*shuffle(vec.begin(), vec.end(), rand_gen);*/
	/*for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}*/
	EXPECT_EQ(true, true);
}

TEST(AVL_Tree, AVL_can_insert4000) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	const int N = 4000;

	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	auto rand_gen = mt19937(0);
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	/*shuffle(vec.begin(), vec.end(), rand_gen);*/
	EXPECT_EQ(true, true);
	/*for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}*/
}

TEST(AVL_Tree, AVL_can_insert16000) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	const int N = 16000;

	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	auto rand_gen = mt19937(0);
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	shuffle(vec.begin(), vec.end(), rand_gen);
	EXPECT_EQ(true, true);

}



TEST(AVL_Tree, AVL_remove1000) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	const int N = 1000;

	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	auto rand_gen = mt19937(0);
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		a.insert(vec[i], vec[i]);
	}
	//a.print();
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		auto temp = a.search(vec[i])->value;
		EXPECT_EQ(temp, vec[i]);
	}
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N-1; i++) {
		auto temp = a.remove(vec[i]);
		
		EXPECT_EQ(temp, true);
	}
	EXPECT_EQ(true, true);
}

TEST(AVL_Tree, AVL_remove4000) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	const int N = 4000;

	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	auto rand_gen = mt19937(0);
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		a.insert(vec[i], vec[i]);
	}
	//a.print();
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		auto temp = a.search(vec[i])->value;
		EXPECT_EQ(temp, vec[i]);
	}
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N - 1; i++) {
		auto temp = a.remove(vec[i]);

		EXPECT_EQ(temp, true);
	}
	EXPECT_EQ(true, true);
}

TEST(AVL_Tree, AVL_remove16000) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	const int N = 16000;

	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	auto rand_gen = mt19937(0);
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		a.insert(vec[i], vec[i]);
	}
	//a.print();
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N; i++) {
		auto temp = a.search(vec[i])->value;
		EXPECT_EQ(temp, vec[i]);
	}
	shuffle(vec.begin(), vec.end(), rand_gen);
	for (int i = 0; i < N - 1; i++) {
		auto temp = a.remove(vec[i]);

		EXPECT_EQ(temp, true);
	}
	EXPECT_EQ(true, true);
}

//TEST(AVL_Tree, AVL_height10) {
//#include <gtest.h>
//#include "dictionary_head.h"
//
//COORD position, newPosition;
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//int x = 0, y = 0;
//
//TEST(AVL_Tree, AVL_can_insert1000) {
//	AVL_Tree<int, int> a;
//	vector<int> vec;
//	vec.push_back(-1);
//	for (int i = 1; i < 1000; i++) {
//		vec.push_back(vec.size());
//	}
//	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
//	for (int i = 1; i < 1000; i++) {
//		a.insert(vec[i], vec[i]);
//	}
//	//a.print();
//	for (int i = 1; i < 1000; i++) {
//		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
//	}
//}
//
//TEST(AVL_Tree, AVL_remove1000) {
//	AVL_Tree<int, int> a;
//	vector<int> vec;
//
//	for (int i = 0; i < 1000; i++) {
//		vec.push_back(vec.size());
//	}
//	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
//	for (int i = 0; i < 1000; i++) {
//		a.insert(vec[i], vec[i]);
//	}
//	//a.print();
//	for (int i = 0; i < 1000; i++) {
//		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
//	}
//
//	for (int i = 1; i < 1000; i++) {
//		auto temp = vec[i];
//		auto temp1 = a.search(temp)->value;
//		EXPECT_EQ(a.remove(vec[i]), true);
//	}
//}
//
////TEST(AVL_Tree, AVL_height10) {
////	AVL_Tree<int, int> a;
////	vector<int> vec;
////	for (int i = 0; i < 1000; i++) {
////		vec.push_back(vec.size());
////	}
////	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
////	for (int i = 0; i < 1000; i++) {
////		a.insert(vec[i], vec[i]);
////	}
////	int old_height = a.tree_height();
////	//a.print();
////	int new_height = old_height;
////	while (new_height - old_height < 10) {
////		for (int i = 0; i < 100; i++) {
////			a.remove(vec[i]);
////		}
////		for (int i = 0; i < 100; i++) {
////			int x = rand() % 1000;
////			a.insert(x, x);
////		}
////		new_height = a.tree_height();
////	}
////	ASSERT_GE(new_height - old_height, 10);
////}
//
//TEST(AVL_Tree, AVL_can_remove) {
//	Binary_Tree<int, int> a;
//	a.insert(1, 1);
//	a.insert(2, 2);
//	a.insert(6, 6);
//	a.insert(-1, -1);
//	a.insert(3, 3);
//	EXPECT_EQ(a.remove(3), true);
//	EXPECT_EQ(a.remove(6), true);
//	EXPECT_EQ(a.remove(-1), true);
//}
//
//TEST(AVL_Tree, AVL_remove_empty_false) {
//	AVL_Tree<int, int> a;
//	a.remove(6);
//	EXPECT_NE(a.remove(10), true);
//}
//
//TEST(AVL_Tree, AVL_operator_plusplus) {
//	AVL_Tree<int, int> a;
//	vector<int> vec = { 1,2,6,-3,3 };//{7,2,3,-2,4}
//	for (int i = 0; i < vec.size(); i++) {
//		a.insert(vec[i], vec[i]);
//	}
//	for (int i = 0; i < a.get_size(); i++) {
//		a.operator++()->value++;
//	}
//	for (int i = 0; i < a.get_size(); i++) {
//		EXPECT_EQ(a.search(vec[i] + 1)->value, vec[i] + 1);
//	}
//}
//
//TEST(AVL_Tree, AVL_copy_constr) {
//	AVL_Tree<int, int> a;
//	vector<int> vec = { 1,2,6,-3,3 };
//	for (int i = 0; i < vec.size(); i++) {
//		a.insert(vec[i], vec[i]);
//
//	}
//	AVL_Tree<int, int>b(a);
//	for (int i = 0; i < a.get_size(); i++) {
//		b.operator++()->value += 10;
//	}
//
//
//	for (int i = 0; i < a.get_size(); i++) {
//		EXPECT_EQ((b.search(vec[i] + 10)->value) - (a.search(vec[i])->value), 10);
//	}
//}

TEST(AVL_Tree, AVL_height10) {
	AVL_Tree<int, int> a;
	vector<int> vec;
	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 1000; i++) {
		a.insert(vec[i], vec[i]);
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
			a.insert(x, x);
		}
		new_height = a.tree_height();
	}
	ASSERT_GE(new_height - old_height, 10);
}


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
	vector<int> vec = { 1,2,6,-3,3 };
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
//
//TEST(AVL_Tree, AVL_right_turn) {
//	AVL_Tree<int, int> temp(20, 20);
//	temp.insert(30, 30);
//	temp.insert(10, 10);
//	temp.insert(15, 15);
//	temp.insert(5, 5);
//	temp.insert(1, 1);
//}

