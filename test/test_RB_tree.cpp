#include <gtest.h>
#include "dictionary_head.h"




TEST(RB_Tree, RB_can_insert1000) {
	RB_Tree<int, int> a;
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