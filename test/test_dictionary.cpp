#include <gtest.h>
#include "dictionary_head.h"

TEST(Table, table_can_insert) {
	Table <int, string> a;
	a.insert(2, "sas");
	EXPECT_EQ(a.search(2)->second, "sas");
}

TEST(Table, table_insert_can_change_field) {
	Table <int, string> a;
	a.insert(2, "sas");
	a.insert(2, "52 yeah");
	EXPECT_EQ(a.search(2)->second, "52 yeah");
}

TEST(Table, table_cant_remove_empty) {
	Table <int, string> a;
	EXPECT_EQ(a.Remove(2) , false);
}

TEST(Table, table_can_remove) {
	Table <int, string> a;
	a.insert(2, "test");
	EXPECT_EQ(a.Remove(2), true);
}

TEST(Table, table_can_operator)
{
	Table <int, string> a;
	a.insert(2, "sas");
	a[2]->second = "tttt";
	ASSERT_EQ(a.search(2)->second, "tttt");
}

TEST(Table, access_operator_throws_then_empty) {
	Table<int, string> a;
	ASSERT_ANY_THROW(a[2]);
}

TEST(Table, can_copy_another_table) {
	Table<int, string> a;
	a.insert(0, "a");
	Table<int, string> b(a);
	EXPECT_EQ(b.search(0)->second, "a");
}

TEST(Table, copied_table_has_its_own_mem) {
	Table<int, string> a;
	a.insert(0, "a");
	Table<int, string> b(a);
	b[0]->second = "b";
	EXPECT_NE(a.search(0)->second, b.search(0)->second);
}
