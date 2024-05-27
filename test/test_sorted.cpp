#include <gtest.h>
#include "Tables.h"

TEST(Sorted_Table, sorTable_can_insert) {
	Sorted_Table<int, string> a;
	a.insert(2, "two");
	EXPECT_EQ(2, a.search(2)->first);
	EXPECT_EQ("two", a.search(2)->second);
}

TEST(Sorted_Table, sorTable_insert_in_same_key) {
	Sorted_Table<int, string> a;
	a.insert(2, "hell yeah");
	a.insert(2, "two");
	EXPECT_EQ(2, a.search(2)->first);
	EXPECT_EQ("two", a.search(2)->second);
}

TEST(Sorted_Table, sorTable_can_remove) {
	Sorted_Table<int, string> a;
	a.insert(1, "one");
	a.insert(2, "two");
	EXPECT_EQ(true, a.remove(1));
	EXPECT_EQ(true, a.remove(2));
}

TEST(Sorted_Table, sorTable_cant_remove_empty) {
	Sorted_Table <int, string> a;
	EXPECT_EQ(a.remove(2), false);
}

TEST(Sorted_Table, sorTable_can_search) {
	Sorted_Table<int, string> a;
	a.insert(2, "two");
	a.insert(1, "ine");
	a.insert(213, "four");
	a.insert(112, "three");
	EXPECT_EQ(112, a.search(112)->first);
	EXPECT_EQ("four", a.search(213)->second);
}

TEST(Sorted_Table, sorTable_operator) {
	Sorted_Table<int, string> a;
	a.insert(2, "two");
	a[2]->second = "notasame";
	ASSERT_EQ(a.search(2)->second, "notasame");
}

TEST(Sorted_Table, sorTable_operator_adds_new_key) {
	Sorted_Table<int, string> a;
	a[2]->second = "sas";
	ASSERT_EQ("sas", a[2]->second);
}

TEST(Sorted_Table, sorTable_has_its_own_mem) {
	Sorted_Table<int, string> a;
	a.insert(2, "two");
	Sorted_Table<int, string> b(a);
	b[2]->second = "other";
	ASSERT_NE(a.search(2)->second, b.search(2)->second);
}
