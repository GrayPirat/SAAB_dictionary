#include <gtest.h>
#include "dictionary_head.h"




TEST(RB_Tree, RB_can_insert1000) {
	RB_Tree<int, int> a;
	vector<int> vec;

	for (int i = 0; i < 1000; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < 1000; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	EXPECT_EQ(1, 1);
}

TEST(RB_Tree, RB_can_insert4000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	int N = 4000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	EXPECT_EQ(1, 1);
}

TEST(RB_Tree, RB_can_insert16000) {
	RB_Tree<int, int> a;
	vector<int> vec;
	int N = 16000;
	for (int i = 0; i < N; i++) {
		vec.push_back(vec.size());
	}
	shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
	for (int i = 0; i < N; i++) {
		auto temp = vec[i];
		a.insert(temp, temp);
	}
	EXPECT_EQ(1, 1);
}

TEST(RB_Tree, AVL_remove1000) {
	RB_Tree<int, int> a;
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
	for (int i = 0; i < N; i++) {
		auto temp = a.remove(vec[i], vec[i]);

		EXPECT_EQ(temp, true);
	}
	EXPECT_EQ(true, true);
}

TEST(RB_Tree, AVL_remove4000) {
	RB_Tree<int, int> a;
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
	for (int i = 0; i < N; i++) {
		auto temp = a.remove(vec[i], vec[i]);

		EXPECT_EQ(temp, true);
	}
	EXPECT_EQ(true, true);
}

TEST(RB_Tree, AVL_remove16000) {
	RB_Tree<int, int> a;
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
	for (int i = 0; i < N; i++) {
		auto temp = a.remove(vec[i], vec[i]);

		EXPECT_EQ(temp, true);
	}
	EXPECT_EQ(true, true);
}