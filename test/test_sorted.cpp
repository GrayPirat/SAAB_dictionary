#include <gtest.h>
#include "dictionary_head.h"

TEST(Sorted_Table, sort_can_search) {
	Sorted_Table<int, string> a;
	a.insert(2, "b");
	a.insert(1, "a");
	a.insert(6576, "c");
	EXPECT_EQ("c", a.search(6576));
}
