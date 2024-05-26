#include <gtest.h>
#include <random>
#include <chrono>
#include <numeric>
#include "dictionary_head.h"

TEST(Binary_and_AVL_Trees_and_RBTree, time_insert_random_values) {
    RB_Tree<int, int> rb;
    AVL_Tree<int, int> avl;
    Binary_Tree<int, int> tree;
    const int N = 10000000;
    std::vector<int> randInsert(N);
    std::vector<int> randRemove(N);
    std::iota(randInsert.begin(), randInsert.end(), 0);
    std::iota(randRemove.begin(), randRemove.end(), 0);
    std::mt19937 g(0);
    std::shuffle(randInsert.begin(), randInsert.end(), g);
    std::shuffle(randRemove.begin(), randRemove.end(), g);
    auto t_start_insert_bin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        tree.insert(randInsert[i], 1);
    }
    auto t_end_insert_bin = std::chrono::high_resolution_clock::now();

    auto t_start_insert_avl = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        avl.insert(randInsert[i], 1);
    }
    auto t_end_insert_avl = std::chrono::high_resolution_clock::now();

    auto t_start_insert_rb = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        rb.insert(randInsert[i], 1);
    }
    auto t_end_insert_rb = std::chrono::high_resolution_clock::now();

    auto t_start_find_bin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(tree.search(i)->value, 1);
    }
    auto t_end_find_bin = std::chrono::high_resolution_clock::now();

    auto t_start_find_avl = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(avl.search(i)->value, 1);
    }
    auto t_end_find_avl = std::chrono::high_resolution_clock::now();

    auto t_start_find_rb = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(rb.search(i)->value, 1);
    }
    auto t_end_find_rb = std::chrono::high_resolution_clock::now();

    auto t_start_remove_bin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        tree.remove(randRemove[i]);
    }
    auto t_end_remove_bin = std::chrono::high_resolution_clock::now();

    auto t_start_remove_avl = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        avl.remove(randRemove[i]);
    }
    auto t_end_remove_avl = std::chrono::high_resolution_clock::now();

    auto t_start_remove_rb = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        rb.remove(randRemove[i], 1);
    }
    auto t_end_remove_rb = std::chrono::high_resolution_clock::now();

    double insert_bin_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_insert_bin - t_start_insert_bin).count();
    double insert_avl_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_insert_avl - t_start_insert_avl).count();
    double insert_rb_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_insert_rb - t_start_insert_rb).count();
    double find_bin_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_find_bin - t_start_find_bin).count();
    double find_avl_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_find_avl - t_start_find_avl).count();
    double find_rb_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_find_rb - t_start_find_rb).count();
    double remove_bin_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_remove_bin - t_start_remove_bin).count();
    double remove_avl_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_remove_avl - t_start_remove_avl).count();
    double remove_rb_elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end_remove_rb - t_start_remove_rb).count();
    //double ratio_insert = insert_avl_elapsed_time_ms / insert_bin_elapsed_time_ms;
    //double ratio_find = find_avl_elapsed_time_ms / find_bin_elapsed_time_ms;
    //double ratio_remove = remove_avl_elapsed_time_ms / remove_bin_elapsed_time_ms;

    std::cout << "Insertions time: binary tree: " << insert_bin_elapsed_time_ms << ", avl tree: " << insert_avl_elapsed_time_ms << ", rb tree" << insert_rb_elapsed_time_ms << std::endl;
    //std::cout << "Binary tree is faster in " << ratio_insert << " times" << std::endl;
    std::cout << "Find time: binary tree: " << find_bin_elapsed_time_ms << ", avl tree: " << find_avl_elapsed_time_ms << ", rb tree" << find_rb_elapsed_time_ms << std::endl;
    //std::cout << "Binary tree is faster in " << ratio_find << " times" << std::endl;
    std::cout << "Remove time: binary tree: " << remove_bin_elapsed_time_ms << ", avl tree: " << remove_avl_elapsed_time_ms << ", rb tree" << remove_rb_elapsed_time_ms << std::endl;
    //std::cout << "Binary tree is faster in " << ratio_remove << " times" << std::endl;
}