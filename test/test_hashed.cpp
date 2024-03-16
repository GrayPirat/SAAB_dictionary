#include <gtest.h>
#include "dictionary_head.h"

TEST(Hash_Table, hash_can_insert) {
	Hash_Table<int, string> a(200);
	a.insert_hash(234,"gold");
	a++;
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
	a.insert_hash(2, 0);
	a.insert_hash(3, 0);
	//auto itet_b;// = a.begin();
	//while (itet_b != itet_b.end()) {
	//	//EXPECT_EQ(itet_b->first, a[i]->first);
	//	//EXPECT_EQ(itet_b->second, a[i]->second);
	//	iter_b..second++;
	//	itet_b++;
	//}
	
}