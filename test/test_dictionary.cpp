#include <gtest.h>
#include "dictionary_head.h"

TEST (Table, can_create_table) {
	ASSERT_NO_THROW(Table<int, string> a);
}

TEST(Table, table_can_insert) {
	Table<int, string> a;
	a.insert(2, "second");
	EXPECT_EQ(a[1], "second");
}

