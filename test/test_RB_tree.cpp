#include <gtest.h>
#include "dictionary_head.h"

COORD position, newPosition;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int x = 0, y = 0;


TEST(RB_Tree, RB_can_insert1000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	auto random_gen = mt19937(0);
	const int N = 1000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), random_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	//a.print();
	for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}

TEST(RB_Tree, RB_can_insert4000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	auto random_gen = mt19937(0);
	const int N = 4000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), random_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	//a.print();
	for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}

TEST(RB_Tree, RB_can_insert16000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	auto random_gen = mt19937(0);
	const int N = 16000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), random_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	//a.print();
	for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}

TEST(RB_Tree, RB_can_insert64000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	auto random_gen = mt19937(0);
	const int N = 64000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), random_gen);
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	//a.print();
	for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}

TEST(RB_Tree, RB_every_son_is_black) {
	RB_Tree<int, int> a;
	vector<int> vec;
	const int N = 1000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}

	for (int i = 1; i <= 10; i++) {
		if (a.search(i)->color == 0) {
			if (a.search(i)->left != NULL)
				EXPECT_EQ(a.search(i)->left->color, 1);
			if (a.search(i)->right != NULL)
				EXPECT_EQ(a.search(i)->right->color, 1);
		}
	}
}

TEST(RB_Tree, RB_Black_Height_Matter) {
	RB_Tree<int, int> a;
	vector<int>vec;
	const int N = 10;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	//a.print();
	int blacks = 0;
	int mx_blacks = -1;
	bool rez = false;
	a.skolko_negrov(blacks, mx_blacks, rez);
	EXPECT_EQ(rez, true);
}

TEST(RB_Tree, RB_can_remove1000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	const int N = 1000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()())); 
		for (int i = 0; i < N; i++) {
			auto temp = vec[i];
			a.insert(temp, temp);
		}
	//a.print();
	for (int i = 0; i < N; i++) {
		EXPECT_EQ(a.search(vec[i])->value, vec[i]);
	}
}