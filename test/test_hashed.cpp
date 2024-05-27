#include <gtest.h>
#include "Tables.h"

TEST(Hash_Table, hash_can_insert) {
	Hash_Table<int, string> a(200);
	a.insert_hash(234,"gold");
	//a++;
	ASSERT_EQ(a.search_hash(234)->second, "gold");
}

TEST(Hash_Table, hash_can_remove) {
	Hash_Table<int, string> a(200);
	a.insert_hash(234, "gold");
	EXPECT_EQ(true, a.remove_hash(234));
	a.insert_hash(334, "silver");
	EXPECT_EQ(true, a.remove_hash(334));
}

TEST(Hash_Table, hash_can_insert_in_same_hash) {
	Hash_Table<int, string> a(200);
	a.insert_hash(234, "gold");
	a.insert_hash(434, "silver");
	EXPECT_EQ(a.search_hash(234)->second, "gold");
	EXPECT_EQ(a.search_hash(434)->second, "silver");
}

TEST(Hash_Table, hash_has_its_own_mem) {
	Hash_Table<int, string> a(200);
	a.insert_hash(234, "a");
	Hash_Table<int, string> b(a);
	b[234]->second = "other";
	ASSERT_NE(a.search_hash(234)->second, b.search_hash(234)->second);
}

TEST(Hash_Table, hash_operator) {
	Hash_Table<int, string> a(200);
	a[456]->second = "one thing";
	ASSERT_EQ(a.search_hash(456)->second, "one thing");
}

TEST(Hash_Table, hash_can_double_insert) {
	Hash_Table<double, string> a(213);
	a.insert_hash(2.345, "a");
	ASSERT_EQ(a.search_hash(2.345)->second, "a");
}

TEST(Hash_Table, hash_iterator_test) {
	Hash_Table<int, int> a(200);
	int i = 0;
	a.insert_hash(0, 0);
	a.insert_hash(1, 207);
	a.insert_hash(2, 1);
	a.insert_hash(201, 0);
	a.operator++()->second = 1;
	a.operator++()->second = 2;
	a.operator++()->second = 3;
	a.operator++()->second = 4;
	EXPECT_EQ(a.search_hash(0)->second, 1);
	EXPECT_EQ(a.search_hash(1)->second, 2);
	EXPECT_EQ(a.search_hash(2)->second, 4);
	EXPECT_EQ(a.search_hash(201)->second, 3);
}

TEST(Hash_Table, hash_iterator_test2) {
	Hash_Table<int, int> a(0);
	int i = 0;
	a.insert_hash(0, 0);
	a.insert_hash(1, 207);
	a.insert_hash(2, 1);
	a.insert_hash(201, 1);
	a.insert_hash(202, 2);
	a.insert_hash(203, 3);
	a.insert_hash(204, 4);
	a.insert_hash(205, 5);
	a.insert_hash(206, 6);
	int size = a.size();
	EXPECT_EQ(size, 10);
}