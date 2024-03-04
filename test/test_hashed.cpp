#include <gtest.h>
#include "dictionary_head.h"

TEST(Hash_Table, hash_can_insert) {
	Hash_Table<int, string> a;
	a.insert_hash(234,"gold");
	ADD_FAILURE();
	//EXPECT_EQ(a.search_hash(234)->second, "gold");
}

TEST(Hash_Table, hash_can_insert_in_same_hash) {
	ADD_FAILURE();
}

TEST(Hash_Table, hash_can_remove) {
	ADD_FAILURE();
}

TEST(Hash_Table, hash_has_its_own_mem) {
	ADD_FAILURE();
}

TEST(Hash_Table, hash_s) {
	ADD_FAILURE();
}

TEST(Hash_Table, hash_can_remove) {
	ADD_FAILURE();
}

TEST(Hash_Table, hash_can_remove) {
	ADD_FAILURE();
}
